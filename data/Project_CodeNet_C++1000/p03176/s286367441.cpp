#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
//#define int long long
#define len(x) (int)(x).size()     
#define all(x) (x).begin(), (x).end()
#define test int _; cin >> _; while(_--)
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
 
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
 
inline ll gcd(ll a, ll b){while(b){ a %= b; swap(a, b); } return a; }
inline ll mod(ll a, ll b){return ((a%b)+b)%b;}
inline ll expo(ll b, ll p, ll m = MOD){
  ll ans = 1; 
  while(p > 0){
    if(p&1LL) ans = mod(ans*b, m); 
    b = mod(b*b, m); 
    p >>= 1LL;
  } 
  return ans;
}
 
////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5+5;

ll bit[N];
int n;

ll query(int idx){
  ll ret = 0;
  for(; idx > 0; idx -= (idx & -idx)){
    ret = max(ret, bit[idx]);
  }
  return ret;
}

void updt(int idx, ll value){
  for(; idx <= n; idx += (idx & -idx)){
    bit[idx] = max(bit[idx], value);
  }
}

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int i = 0; i < n; i++){
    ll cur;
    cin >> cur;
    ll best = query(h[i]);
    updt(h[i], cur+best);
  }
  cout << query(n) << '\n';
  return 0; 
}