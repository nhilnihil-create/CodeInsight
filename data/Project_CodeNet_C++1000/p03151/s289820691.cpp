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
vector<ll> pw2(62,1);vector<ll> pw10(19,1);

int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N; cin>>N;
    vector<ll> A(N);
    vector<ll> B(N);
    ll sumA=0,sumB=0;
    rep(i,N){
        cin>>A[i];
        sumA+=A[i];
    }
    rep(i,N){
        cin>>B[i];
        sumB+=B[i];
    }
    
    if(sumB>sumA){
        cout<<-1<<endl;
        return 0;
    }
    
    ll ans=0,sum=0;
    vector<ll> X;
    rep(i,N){
        if(A[i]<B[i]){
            ans++;
            sum+=(B[i]-A[i]);
        }
        else if(A[i]>B[i]){
            X.pb(A[i]-B[i]);
        }
    }
    sort(all(X),greater<ll>());
    
    if(ans==0){
        cout<<0<<endl;
        return 0;
    }
    
    ll tmp=0;
    rep(i,sz(X)){
        ans++;
        tmp+=X[i];
        if(tmp>=sum) break;
    }
    
    cout<<ans<<endl;
}

