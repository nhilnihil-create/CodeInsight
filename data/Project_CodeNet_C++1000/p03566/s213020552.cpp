#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
typedef pair<int, int> pii;


int main() {
	int n;
	cin >> n;
	vector<int> t(n+2);
	vector<int> sum_t(n+3);
	for (int i = 1; i <=n;i++) {
		cin >> t[i];
		sum_t[i+1] +=sum_t[i] + t[i];
	}
	t[n] = 0;
	sum_t[n + 2] = sum_t[n + 1];
	vector<int> v_max(n+2);
	for (int i = 1; i <=n;i++) {
		cin >> v_max[i];
	}
	v_max[n+1] = 0;

	double ans = 0;
	double last_v = 0;
	for (double ti = 0; ti <= sum_t[n + 1]; ti+=0.5) {
		double v = 10000;
		for (int i = 0; i <= n + 1;i++) {
			if (ti < sum_t[i]) {
				v = min(v, v_max[i] + sum_t[i] - ti);
			}
			else if (ti > sum_t[i + 1]) {
				v = min(v, v_max[i] + ti - sum_t[i + 1]);


			}
			else {
				v = min(v, 1.0 * v_max[i]);
			}
			//cout << v << " " << i << endl;
		}

		ans += (v + last_v)*0.25;
		//cout << ans << " " << v << endl;
		last_v = v;

	}
	printf("%lf", ans);
}

