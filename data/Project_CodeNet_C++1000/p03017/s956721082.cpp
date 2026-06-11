//Kenken Race

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a) vector<ll>a(n);rep(i,0,n)cin>>a[i]
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
    int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    string s;cin>>s;
    a--;b--;c--;d--;
    bool flag=true;
    if(c>d){
        rep(i,a+1,c+1){
            if(s[i]=='#'&&s[i-1]=='#')flag=false;
        }
        if(!flag){cout<<"No"<<nnn;return 0;}
        bool miti = false;
        rep(i,b,d+1){
            if(s[i]=='.'&&s[i-1]=='.'&&s[i+1]=='.')miti=true;
        }
        if(!miti){cout<<"No"<<nnn;return 0;}
    }else{
        rep(i,a+1,d+1){
            if(s[i]=='#'&&s[i-1]=='#')flag=false;
            if(!flag){cout<<"No"<<nnn;return 0;}
        }
    }
    cout<<"Yes"<<nnn;
    return 0;
}