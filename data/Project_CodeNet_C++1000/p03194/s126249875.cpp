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
	int pow(int a, int b) {
		if (b == 0) return 1;
		if (b % 2) return a*pow(a, b - 1);
		int tmp = pow(a, b / 2);
		return tmp*tmp;
	}
	
	void ans() {
		cin >> N >> P;
		if (N == 1) {
			cout << P << "\n";
			return;
		}
		ll Q = P;
		int res = 1;
		for (ll i = 2;i*i <= P;i++) {
			ll tmp = 0;
			while (Q%i == 0) {
				if (++tmp == N) {
					res *= i;
					tmp = 0;
				}
				Q /= i;
			}
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