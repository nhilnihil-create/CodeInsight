#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<stack>
#include<queue>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

class question {
public:
	ll N, P;
	ll pow(ll a, ll b) {
		if (b == 0) return 1;
		if (b % 2) return a*pow(a, b - 1);
		ll tmp = pow(a, b / 2);
		return tmp*tmp;
	}
	void ans() {
		cin >> N >> P;
		int res;
		if (N == 1) {
			cout << P << "\n";
			return;
		}
		for (int i = 1;pow(i, N) <= P && pow(i, N) > 0;i++) {
			if (P%pow(i, N) == 0) res = i;
		}
		cout << res << "\n";
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	question q;
	q.ans();

	return 0;
}

