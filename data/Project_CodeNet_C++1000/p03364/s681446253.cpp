#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;cin>>n;
vector<string> s(n);
vector<P> ab(n*n);
for(int i=0;i<n;i++)cin>>s[i];
ll ans=0;
for(int t=0;t<n;t++){
    bool ok=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             if(s[(j+t)%n][(i+n-t)%n]!=s[i][j])ok=false;
        }
    }
    if(ok)ans++;
}
cout<<ans*n<<endl;
}