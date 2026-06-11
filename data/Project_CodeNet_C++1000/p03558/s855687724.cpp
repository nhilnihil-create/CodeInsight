#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <functional>
#include <typeinfo>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>

using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define reprrev(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); i--)
#define reprev(i, n) reprrev(i, 0, n)
#define mp(a, b) make_pair(a, b)
#define all(vec) (vec).begin(), (vec).end()
#define yn(formula) (formula) ? (cout << "Yes" << endl) : (cout << "No" << endl)
#define YN(formula) (formula) ? (cout << "YES" << endl) : (cout << "NO" << endl)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;

constexpr double PI = 3.14159265358979323846;
constexpr ll INF = 1ll << 59;
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-7;
constexpr int dy[4] = { 0, 1, 0, -1 };
constexpr int dx[4] = { 1, 0, -1, 0 };

/*<ここから>***********************************************************/


int main()
{
	int K;
	cin >> K;
	vvi g(K);

	rep(i, K) {
		g[i].push_back((i + 1) % K);
		g[i].push_back((i * 10) % K);
	}

	vi visited(K, 0);
	priority_queue<pii> pq;
	pq.push(pii(-1, 1));
	int ans;
	while (!pq.empty()) {

		int crr = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (crr == 0) {
			ans = -cost;
			break;
		}

		visited[crr] = 1;

		if (visited[(crr + 1) % K] == 0) {
			pq.push(pii(-cost - 1, (crr + 1) % K));
		}
		if (visited[(crr * 10) % K] == 0) {
			pq.push(pii(-cost, (crr * 10) % K));
		}
	}

	cout << -ans << endl;

	return 0;
}
