//Special Trains

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, string>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n;cin>>n;
    vector<double>c(n),s(n),f(n);
    rep(i,0,n-1)cin>>c[i]>>s[i]>>f[i];
    rep(i,0,n){
        double t=0;
        rep(j,i,n-1){
            if(t<s[j])t=s[j]+c[j];
            else t=f[j]*ceil(t/f[j])+c[j];
        }
        cout<<(int)t<<nnn;
    }
    return 0;
}