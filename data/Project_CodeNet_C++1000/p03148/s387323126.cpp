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
typedef pair<ll,ll> P;
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

vector<ll> pw2(51,1);vector<ll> pw10(19,1);
int main(){
    {rep1(i,50) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N,K; cin>>N>>K;
    ll ans=0;
    vector<ll> t(N);
    vector<ll> d(N);
    priority_queue<P,vector<P> > sushi;
    priority_queue<P,vector<P>,greater<P> > trash;
    
    rep(i,N){
        cin>>t[i]>>d[i];
        sushi.push(P(d[i],t[i]));
    }
    set<ll> se;
    
    ll point=0;
    rep(i,K){
        point+=sushi.top().a;
        if(se.find(sushi.top().b) != se.ed) trash.push(sushi.top());
        else se.insert(sushi.top().b);
        sushi.pop();
    }
    ans=point+sz(se)*sz(se);
    while(!sushi.empty() && !trash.empty()){
        P tmp=sushi.top();
        if(se.find(tmp.b) != se.ed){
            //何もしない
        }
        else{
            se.insert(tmp.b);
            point-=trash.top().a;
            trash.pop();
            point+=tmp.a;
        }
        sushi.pop();
        chmax(ans,point+sz(se)*sz(se));
    }
    cout<<ans<<endl;
}

