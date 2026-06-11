#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<ll,pair<ll,ll> > > CAKE;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll digsz(ll x){if(x==0) return 1;else{ll ans=0;while(x){x/=10;ans++;}return ans;}}
ll digsum(ll x){ll sum=0;while(x){sum+=x%10;x/=10;}return sum;}
vector<ll> pw2(62,1);

int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    ll X,Y,Z,K; cin>>X>>Y>>Z>>K;
    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);
    rep(i,X) cin>>A[i];
    rep(i,Y) cin>>B[i];
    rep(i,Z) cin>>C[i];
    sort(all(A),greater<ll>());
    sort(all(B),greater<ll>());
    sort(all(C),greater<ll>());
    priority_queue<CAKE> que;
    //CAKE: a b.a b.b.a b.b.b
    que.push( mp(A[0]+B[0]+C[0],mp(0,mp(0,0))) );
    set<pair<ll,pair<ll,ll> > > se;
    ll i=0;
    while(i<K){
        ll c=que.top().a; cout<<c<<endl;
        ll AA=que.top().b.a,BB=que.top().b.b.a,CC=que.top().b.b.b;
        que.pop();
        if(AA+1<X && BB<Y && CC<Z && se.find( mp(AA+1,mp(BB,CC)) )==se.ed){
            que.push( mp(A[AA+1]+B[BB]+C[CC],mp(AA+1,mp(BB,CC))) );
            se.insert(mp(AA+1,mp(BB,CC)));
        }
        if(AA<X && BB+1<Y && CC<Z && se.find( mp(AA,mp(BB+1,CC)) )==se.ed){
            que.push( mp(A[AA]+B[BB+1]+C[CC],mp(AA,mp(BB+1,CC))) );
            se.insert(mp(AA,mp(BB+1,CC)));
        }
        if(AA<X && BB<Y && CC+1<Z && se.find( mp(AA,mp(BB,CC+1)) )==se.ed){
            que.push( mp(A[AA]+B[BB]+C[CC+1],mp(AA,mp(BB,CC+1))) );
            se.insert(mp(AA,mp(BB,CC+1)));
        }
        i++;
    }
}

