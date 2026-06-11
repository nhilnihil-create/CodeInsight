#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <numeric>
#include <string.h>
#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define repn(i, x) for (int i = 1; i <= (int)(x); i++)
#define repr(i, x) for (int i = ((int)(x) - 1); i >= 0; i--)
#define reprn(i, x) for (int i = ((int)(x)); i > 0; i--)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector<int> nums;
	int now = 1;
	int cnt = 0;
	for (unsigned int i = 0; i < n; ++i) {
		if (s[i] == (char)(now + '0')) cnt++;
		else {
			nums.push_back(cnt);
			now = 1- now;
			cnt = 1;
		}
	}
	if (cnt != 0) nums.push_back(cnt);
	if (nums.size() % 2 == 0) nums.push_back(0);
	int add = 2 * k + 1;
	int ans = 0;
	vector<int> sum(nums.size() + 1, 0);
	for (int i = 0; i < nums.size(); ++i) {
		sum[i + 1] = sum[i] + nums[i];
	}
	for (int i = 0; i < nums.size(); i += 2) {
		int left = i;
		int right = min(i + add, (int)nums.size());
		int tmp = sum[right] - sum[left];
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return;
}

int main() {
	solve();
  return 0;
}