//AB Substrings

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
    vecrep(n,s,string);
    int b=0,a=0,ans=0,ab=0;
    rep(i,0,n){
        if(s[i][0]=='B')b++;
        if(s[i][s[i].size()-1]=='A')a++;
        if(s[i][0]=='B'&&s[i][s[i].size()-1]=='A')ab++;
        rep(j,0,s[i].size()-1){
            if(s[i][j]=='A'&&s[i][j+1]=='B')ans++;
        }
    }
    ans+=min(min(a,b),n-1);
    if(a==ab&&b==ab&&ab!=n&&ab!=0)ans-=1;
    cout<<ans<<nnn;
    return 0;
}