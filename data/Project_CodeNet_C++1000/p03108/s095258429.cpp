#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< ll, ll >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define tc int t; cin >> t; while(t--)
#define int ll
using namespace std;
string repeat(string s, int n) {
    string s1 = "";
    for (int i=0; i<n;i++)
        s1+=s;
    return s1;
}
string getString(char x) {
    string s(1, x);
    return s;
}

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}
struct dsu {
    vector<ll> par, rank;
    dsu(ll n): par(n+1), rank(n+1) {
        for (ll i = 0; i <= n; i++) {
            par[i] = i;
            rank[i]= 1;
        }
    }
    ll root(ll a) {
        if (a == par[a]) return a;
        return par[a] = root(par[a]);
    }
    void merge(ll a, ll b) {
        a = root(a);
        b = root(b);
        if (a == b) return;
        if (rank[a] > rank[b]) swap(a, b);
        rank[a] += rank[b];
        par[b] = a;
    }
};
void  solve(){
  ll n,m,x,y;
  cin>>n>>m;
  vector<pair<ll,ll> > edg(m);
  rep(i,0,m) cin>>edg[i].f>>edg[i].s;

  dsu d(n);
  multiset<ll> s1;
  // map<int,int> m1;
  // rep(i,0,n) s1.insert(1);
  vector<ll> ans(m);
  ll sum=n;
  rrep(i,m-1,0){
    ans[i]=(n*n-sum)/2;
    pii x=edg[i];
    ll y=d.root(x.f-1),z=d.root(x.s-1);
    if(y!=z){
      ll num1=d.rank[y],num2=d.rank[z];
      // s1.erase(num1),s1.erase(num2);
      // s1.insert(num1+num2);
      // cout<<num1<<" "<<num2<<endl;
      sum-=(num1*num1+num2*num2);
      sum+=((num1+num2)*(num1+num2));
      d.merge(y,z);
    }
  }
  rep(i,0,m) cout<<ans[i]<<endl;
}
int32_t main(){
    optimizeIO();
    // tc
    { solve();
    }
}
