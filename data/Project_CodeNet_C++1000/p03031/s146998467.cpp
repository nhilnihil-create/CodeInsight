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
vector<ll> pw2(62,1);vector<ll> pw10(19,1);

int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N,M; cin>>N>>M;
    ll ans=0;
    vector<ll> k(M);
    vector<ll> p(M);
    vector<vector<ll> > s(M,vector<ll>(N));
    rep(i,M){
        cin>>k[i];
        rep(j,k[i]){
            cin>>s[i][j];
        }
    }
    rep(i,M) cin>>p[i];
    rep(i,pw2[N]){
        //BIT全探索
        vector<ll> BIT(N);
        ll tmps=i;
        rrep(i2,N){
            BIT[i2]=tmps/pw2[i2];
            tmps%=pw2[i2];
        }
        
        //check
        bool check=true;
        rep(j,M){
            ll tmp=0;
            rep(l,k[j]){
                if(BIT[s[j][l]-1]==1) tmp++;
            }
            if(tmp%2!=p[j]) check=false;
        }
        
        if(check) ans++;
    }
    cout<<ans<<endl;
}

