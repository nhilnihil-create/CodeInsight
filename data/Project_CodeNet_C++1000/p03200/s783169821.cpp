#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0)
#define print(x) cout << x;
#define println(x) cout << x << endl;
#define printd(x, f) cout << fixed << setprecision(f) << x << endl;

#define PB push_back
#define MP make_pair
#define F first
#define S second

#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PI acos(-1.0)

int main()
{
  string S; cin >> S;
  ll cnt = 0;
  ll b = 0;
  REP(i, SIZE(S)) {
    if (S[i] == 'B') b++;
    else if (S[i] == 'W') cnt += b;
  }
  println(cnt);
  return 0;
}
