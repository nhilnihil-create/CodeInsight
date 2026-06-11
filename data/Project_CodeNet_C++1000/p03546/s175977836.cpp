//Wall

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, string>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

signed main (){
    int h,w;cin>>h>>w;
    vector<vector<int>>c(10,vector<int>(10));
    rep(i,0,10)rep(j,0,10)cin>>c[i][j];
    rep(k,0,10)rep(i,0,10)rep(j,0,10){
        //chmin(もともと, iからk + kからj);
        chmin(c[i][j],c[i][k]+c[k][j]);
    }
    int ans{};
    rep(i,0,h*w){
        int a;cin>>a;
        if(a>=0)ans+=c[a][1];
    }
    cout<<ans<<nnn;
    return 0;
}