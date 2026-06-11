#include <bits/stdc++.h>
using namespace std;

// TYPEDEF
// ----------------------------------------
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> Pair;
typedef vector<ll> vll;
typedef vector<vector<ll>> Graph;
typedef vector<string> vs;
typedef vector<pair<ll, ll>> Pll;
typedef queue<ll> qll;

// REPEAT
// ----------------------------------------
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REPA(i,a) for(ll i=0;i<(ll)(a.size());i++);
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define COUT(a) cout << (a) << endl;
#define ENDL(a) cout << endl;
#define COUTA(i,a) for(ll i=0;i<(ll)(a.size());i++) {cout << (a)[i] << " ";} cout << endl;

// UTIL
// ----------------------------------------
#define pb push_back
#define paired make_pair
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define RSORT(a) sort((a).rbegin(), (a).rend())

// DEBUG
// ----------------------------------------
#ifdef _DEBUG
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
#else
#define debug(x)
#endif

template <typename T>
void debugV(const vector<T> v) {
#ifdef _DEBUG
  rep(i, v.size()) {
    cout << i << ":" << v[i] << " ";
  }
  cout << endl;
#else
  (void)v;
#endif
}

// BIT FLAG
// ----------------------------------------
const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000
const unsigned int BIT_FLAG_8 = (1 << 8); // 0000 0001 0000 0000
const unsigned int BIT_FLAG_9 = (1 << 9); // 0000 0010 0000 0000
const unsigned int BIT_FLAG_10 = (1 << 10); // 0000 0100 0000 0000
const unsigned int BIT_FLAG_11 = (1 << 11); // 0000 1000 0000 0000

// CONST
// ----------------------------------------
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr double PI=3.14159265358979323846; // or M_PI
constexpr int MOD = 1000000007;


void Main() {
  ll n, m;
  cin >> n >> m;

  priority_queue<ll, vector<ll>, greater<ll>> a;
  vector<Pair> cb;

  ll total = 0;
  REP(i, n) {
    ll a_in;
    cin >> a_in;
    a.push(a_in);
    total += a_in;
  }

  REP(i, m) {
    ll b_in, c_in;
    cin >> b_in >> c_in;
    cb.emplace_back(c_in, b_in);
  }

  sort(cb.begin(), cb.end(), greater<Pair>());
  // REP(i, m) {
  //   std::cout << cb[i].first << " " << cb[i].second << endl;
  // }

  ll index = 0;
  ll count = 1;
  REP(i, n) {
    ll target = a.top();
    // cout << index << " " << target << " " << cb[index].first << endl;
    if (target < cb[index].first) {
      a.pop();
      a.push(cb[index].first);
      total = total - target + cb[index].first;
      if (count == cb[index].second) {
        // cout << "count " << count << " " << cb[index].second << endl;
        index++;
        count = 0;
      }
      // COUT(a.top());
      count++;
    }
    else {
      // COUT(i);
      break;
    }
  }
  COUT(total);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}

/*
4 3
1 2
2 3
2 4
2 10
1 100
3 1
*/
