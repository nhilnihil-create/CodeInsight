//March

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
#define cout15(a) printf("%.15f\n",a)
template<class T>inline bool chmin(T& a,T b,bool f){
if(f==1){if(a>b){a=b;return true;}return false;}
else if(f==0){if(a<b){a=b;return true;}return false;}return false;}
typedef pair<ll,string> p;
using g = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n;cin>>n;
    vecrep(n,s,string);
    ll ans = 0;
    vector<ll>r(5,0);
    rep(i,0,n){
        if(s[i][0]=='M')r[0]++;
        if(s[i][0]=='A')r[1]++;
        if(s[i][0]=='R')r[2]++;
        if(s[i][0]=='C')r[3]++;
        if(s[i][0]=='H')r[4]++;
    }
    rep(i,0,5)rep(j,i+1,5)rep(k,j+1,5)ans+=r[i]*r[j]*r[k];
    cout<<ans<<nnn;
    return 0;
}