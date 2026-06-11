#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define repi(i, a, b) for(int i=(a); i>(b); i--)
#define db(x) (cerr << #x << ": " << (x) << '\n')
#define sync ios_base::sync_with_stdio(false), cin.tie(NULL)
#define iceil(n, x) (((n) + (x) - 1) / (x))
#define ll long long
#define gcd __gcd
//#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define sz size()
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define si(a) scanf("%d", &a)
#define sll(a) scanf("%lld", &a)
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC
#define PI acos(-1.0)
#define EPS 1e-9
#define mod 1000000007
#define MOD 1000000007
#define N 300005
using namespace std;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;

//All indexing is 0-based
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
       tree_order_statistics_node_update> ordered_set;
//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar.

//a and b are assumed to be taken modulo p
inline int add(int a, int b, int p = mod){ int c = a + b; if(c >= p) c -= p; return c;}
inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c;}
inline int mul(int a, int b, int p = mod){ return (a * 1ll * b) % p;}

ll x[N], pre[N];

ll sum(int l, int r) {
  ll ans = pre[r];
  if(l > 0) ans -= pre[l-1];
  return ans;
}

int main()
{ 
  #ifdef CP
    freopen("/home/tarun/Desktop/input.txt", "r", stdin);
    //freopen("/home/tarun/Desktop/output.txt", "w", stdout);
  #endif
  sync;
  clock_t clk = clock();
  cerr << "I will return...\n";

  ll n, k; cin >> n >> k;
  rep(i, 0, n) cin >> x[i];
  rep(i, 0, n) {
    pre[i] = x[i];
    if(i) pre[i] += pre[i-1];
  }

  vector<ll> v;
  v.pb(5); v.pb(5);
  while(v.sz < n) {
    v.pb(v.back() + 2);
  }

  ll mn =  1e18;
  rep(t, 1, n + 1) {
    ll val = t * k + n * k; //db(val);
    if(val > mn) continue;
    int i, j;
    i = 0, j = n-1;
    while(j >= 0) {
      val += sum(j - t + 1, j) * v[i++];
      if(val > mn) break;
      j -= t;
     // db(val);
    }
    //db(t), db(val);
    mn = min(mn, val);
  }

  cout << mn << '\n';
 
  cerr << "...don't you ever hang your head.\n";
  cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << '\n';
}

//Compile using:
//g++ -o filename.exe --std=c++11 filename.cpp
//Use -D CP for defining a macro CP in the local environment





