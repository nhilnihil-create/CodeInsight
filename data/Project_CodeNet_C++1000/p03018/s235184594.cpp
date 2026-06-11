//ABC

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define YN(flag) (flag?"Yes":"No")
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    string s,t;cin>>s;
    int ans=0,a=0;
    rep(i,0,s.size()){
        if(i<s.size()-1)if(s[i]=='B'&&s[i+1]=='C'){
            t.pb('D');
            i++;
        }
        else t.pb(s[i]);
    }
    rep(i,0,t.size()){
        if(t[i]=='A')a++;
        else if(t[i]=='D')ans+=a;
        else a=0;
    }
    cout<<ans<<nnn;
    return 0;
}