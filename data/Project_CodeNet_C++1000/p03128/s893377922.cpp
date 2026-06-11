#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
#define pb push_back
#define PI acos(-1.0)
#define EPS 1e-4
#define mp make_pair
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fout(S,x)            cout<<fixed<<setprecision(x)<<(S)<<endl
#define present(c,x) ((c).find(x) != (c).end())
#define T() ll t;cin>>t;while(t--)
#define mem(input,b) memset(input,b,sizeof(input))
#define ff first
#define ss second
#define fread(input) freopen("input","r",stdin)
#define fwrite(b) freopen("b","w",stdout)
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define FOREACH(i,c) for (__typeof ((c).begin()) i = (c).begin() ; i != (c).end() ; i++)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
const int maxn=1e5+5;
const int mod=1e9+7;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;  } return 0;  }
bool lessThan(const string &a, const string &b) {
    if (a == "") {
            return true;
              
    } else if (a.size() == b.size()) {
            return a < b;
              
    } else {
            return a.size() < b.size();             
    }
    
}
int main(){
    fastio;
    ll n,m;
    cin>>n>>m;
    vector<ll> a(m);
    for(int i=0;i<m;++i)
        cin>>a[i];
    vector<string> dp(n+1,"$");
    ll matches[9] = {2,5,5,4,5,6,3,7,6};
    dp[0]="";
    for(int i=0;i<n;++i){
        if(dp[i]=="$")
            continue;
        for(auto x:a){
            if(i+matches[x-1]>n){
                continue;
            }
            if(lessThan(dp[i+matches[x-1]],dp[i]+(char)('0'+x))){
                dp[i+matches[x-1]] = dp[i] + (char)('0'+x);
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}    
