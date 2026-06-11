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

int n, m;
string s;
vi adj[N];
int ar[N][2];
bitset<N> exists;

int main()
{ 
  #ifdef CP
    freopen("/home/tarun/Desktop/input.txt", "r", stdin);
    //freopen("/home/tarun/Desktop/output.txt", "w", stdout);
  #endif
  sync;
  clock_t clk = clock();
  cerr << "I will return...\n";

  cin >> n >> m >> s;
  for(char &c : s) c = tolower(c);
  rep(i, 0, n) exists[i] = 1;
  rep(i, 0, m) {
    int u, v; cin >> u >> v;
    u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
    ar[u][s[v] - 'a']++;
    ar[v][s[u] - 'a']++;
  }

  vi q;

  rep(i, 0, n) {
    if(ar[i][0] == 0 || ar[i][1] == 0) {
      q.push_back(i);
      exists[i] = 0;
    }
  }

  rep(oo, 0, q.sz) {
    int i = q[oo];
    //q.pop();

    for(int j : adj[i]) {
      ar[j][s[i] - 'a']--;
      if(ar[j][s[i] - 'a'] == 0) {
        if(exists[j]) {
          exists[j] = 0;
          q.push_back(j);
        }
      }
    }
  }

  cout << (q.sz == n ? "No\n" : "Yes\n");
 
  cerr << "...don't you ever hang your head.\n";
  cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << '\n';
}

//Compile using:
//g++ -o filename.exe --std=c++11 filename.cpp
//Use -D CP for defining a macro CP in the local environment





