#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long ,long long>pll;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

unsigned long long modpow(unsigned long long n, unsigned long long k, unsigned long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}
vector<ll>parent(1e5+10,-1);
vector<ll>rk(1e5+10,0);
vector<ll>sum(1e5+10,1);
int find_root(int x){
   ll x_root = x;
   while(parent[x_root]!=-1) x_root = parent[x_root];
   return x_root;
}
void union_uv(int x,int y){
   ll x_root = find_root(x);
   ll y_root = find_root(y);
   if(rk[x_root]<rk[y_root]){
    parent[x_root] = y_root;
    sum[y_root] += sum[x_root];
    sum[x_root] = 0;
   }
   else if(rk[x_root]>rk[y_root]){
    parent[y_root] = x_root;
    sum[x_root] += sum[y_root];
    sum[y_root] = 0;
   }
   else{
    rk[x_root]++;
    parent[y_root] = x_root;
    sum[x_root] += sum[y_root];
    sum[y_root] = 0;
   }
}
void solve(){
    ll n,m;cin >> n >> m;
    vector<ll>v(m);
    vector<ll>u(m);
    for(int i = 0;i<m;i++)
        cin >> v[i] >> u[i];
    vector<ll>ans(m+1,n*(n-1)/2);
    for(int i = m-1;i>=0;i--){
        ll vv = find_root(v[i]);ll uu = find_root(u[i]);
        if(vv==uu)
            ans[i] = ans[i+1];
        else{
            ans[i] = ans[i+1] - sum[vv]*sum[uu];
            union_uv(v[i],u[i]);
        }
    }
    for(int i = 1;i<=m;i++)
        cout << ans[i] <<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}