#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<ld> vld;
typedef vector<string> vstr;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)
#define TS to_string
#define ALL(v) (v).begin(), (v).end()
#define endl "\n"

ll INF = 1e9;
ll MOD = 1000000007;
ll LINF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "YES" << endl;}
void no(){ cout << "NO" << endl;}

//-----------------------------------------
//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll n;
  cin >> n;
  vll p(n);
  REP(i,n) {cin >> p[i]; p[i]--;}

  vll tmp(n);
  REP(i,n){
    tmp[p[i]] = i;
  }

  ll ans = n;

  ll t = 0;
  for(ll i = 0; i < n; i++){
    if(i == n - 1){
      ans = min(ans, n - t - 1);
      break;
    }
    if(tmp[i] < tmp[i + 1]){
      t++;
    }
    else{
      ans = min(ans, n - t - 1);
      t = 0;
    }
  }

  cout << ans <<endl;



  return 0;
}

