#include<bits/stdc++.h>
using namespace std;
#define flash ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define all(v) (v).begin(),(v).end() 
#define endl "\n"
#define int long long int
#define ll long long
#define ld long double
const int mod = 1000000007;
const int N=200005;
const int inf=1e18;
int vis[N];
vector<vector<int>>adj(N);


bool isPrime(ll n){if(n<2)return false;for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}
ll power(ll x,ll y){ll res=1;x=x;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res%mod;}
ll gcd(ll a,ll b){if (a==0)return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return (a/gcd(a,b)*b);}
ll max(ll a,ll b){ll ans=a>b?a:b;return ans;}
ll min(ll a,ll b){ll ans=a<b?a:b;return ans;}
void dfs(int x){
    vis[x]=1;
    for(auto i:adj[x]){
        if(!vis[i])
            dfs(i);
    }
}


void fun(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}


signed main(){
    flash;
    fun();
    int t=1;
    //cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        k--;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            if(i==k){
                char c=tolower(s[i]);
                cout<<(char)(c);
            }
            else
                cout<<s[i];
        }
    }
    return 0;
}