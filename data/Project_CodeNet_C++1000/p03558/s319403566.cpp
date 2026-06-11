#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<map>
#include<functional>
#include<set>

#pragma region
using namespace std;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define LOWER(x,y) lower_bound(ALL(x), y) - x.begin() - 1;
#define INF 9223372036854775807
#define MOD 1000000007
#define pb push_back
#define F first 
#define S second
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, ans = 0, sum = 0, cnt = 0, tmp = 0;
string s;
bool flag;
#pragma endregion
#define MAX 111111


ll d[MAX];
bool stt[MAX];
int main(void) {
  ll k, x;
  deque<ll> dq;
  cin >> k;
  FOR(i, 0, k) d[i] = INF;

  d[1] = 1;
  dq.push_front(1);
  while (!dq.empty()) {
	x = dq.front();
	dq.pop_front();
	if (x == 0) break;
	if (stt[x]) continue;
	if (d[(x * 10) % k] > d[x]) {
	  d[(x * 10) % k] = d[x];
	  dq.push_front((x * 10) % k);
	}
	if (d[(x + 1) % k] > d[x] + 1) {
	  d[(x + 1) % k] = d[x] + 1;
	  dq.push_back((x + 1) % k);
	}
	stt[x] = true;
	x = (x * 10) % k;
  }
  cout << d[0] << endl;

  return 0;
}