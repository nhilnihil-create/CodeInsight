#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define pb push_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};
 
template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
struct Timer{
    chrono::system_clock::time_point start, end;
    Timer(){ start = chrono::system_clock::now(); }
    ~Timer(){
        end = chrono::system_clock::now();
        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cerr<<"time : "<<msec<<" ms"<<endl;
    }
};
 
 
 
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Timer TM;

    ll n;
    cin>>n;
    ll t[110]={},v[110]={};
    double dp[110][110];
    rep(i,110)rep(j,110) dp[i][j]=0.0;
    rep(i,n) cin>>t[i];
    rep(i,n) cin>>v[i];
    v[n]=0,v[n+1]=0;
    dp[0][0]=1;
    rep(i,n){
        rep(V,105){
            if(dp[i][V]>0&&V<=v[i]){
                rep(vv,105)if(vv<=v[i]){
                    ll a=v[i]-V;
                    ll b=v[i]-vv;
                    if(a+b<=t[i]){
                        double up=1.0*(V+v[i])*a/2.0;
                        double stay=v[i]*(t[i]-a-b);
                        double down=1.0*(vv+v[i])*b/2.0;
                        chmax(dp[i+1][vv],dp[i][V]+up+stay+down);
                    }
                    else if(t[i]<abs(V-vv)){}
                    else{
                        double x=1.0*(vv-V+t[i])/2.0;
                        double y=1.0*(t[i]-vv+V)/2;
                        double v2=V+x;
                        double up=1.0*(V+v2)*x/2;
                        double down=1.0*(vv+v2)*y/2;
                        chmax(dp[i+1][vv],dp[i][V]+up+down);
                    }                  
                }
            }
            
        }
    }
    cout<<dp[n][0]-1<<endl;
    return 0;
}