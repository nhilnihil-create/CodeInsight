//Problem Set

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
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
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int main (){
    int n;cin>>n;
    map<int,int>d{};
    rep(i,0,n){
        int s;cin>>s;
        d[s]++;
    }
    nvarep(m,t);
    bool flag = true;
    rep(i,0,m){
        if(d[t[i]]<1)flag=false;
        d[t[i]]--;
    }
    cout<<(flag?"YES":"NO")<<nnn;
    return 0;
}