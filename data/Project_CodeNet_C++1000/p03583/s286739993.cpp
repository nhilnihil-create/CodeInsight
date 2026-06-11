#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
#include <iomanip>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60
const double PI = 3.14159265358979323846;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N; cin >> N;
	for (ll i = 1; i <= 3500; i++) {
		for (ll j = 1; j <=i; j++) {
			ll a = N * i * j;
			ll b = 4 * i * j - N * i - N * j;
			if (b>0 && a % b == 0) {
				cout << i << " " << j << " " << a / b << endl;
				return 0;
			}
		}
	}

	return 0;
}