#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>
#include <cstdint>
#include <cctype>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vs = vector<string>;
using Vb = vector<bool>;
using the = pair<int, int>;

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

int main() {
	int d, g;
	cin >> d >> g;
	Vi P(d), C(d);
	rep(i, d)  cin >> P[i] >> C[i];

	
	int ans = INT_MAX;
	//bit全探索
	for (int bit = 0; bit < (1 << d); ++bit)
	{
		int sum = 0;
		int cnt = 0;
		Vi R;
		for (int i = 0; i < d; ++i) {
			if (bit & (1 << i)) { // i が bit に入るかどうか
				sum += (i + 1) * 100 * P[i] + C[i];
				cnt += P[i];
			}
			else {
				R.push_back(i);
			}
		}
		sort(R.begin(), R.end());

		bool f1 = false, f2 = false;;
		while (sum < g) {
			int j = R[R.size() - 1];
			R.pop_back();
			rep(k, P[j] - 1) {
				sum += 100 * (j + 1);
				cnt++;
				//cout << sum << " " << cnt << endl;
				if (sum >= g) {
					f2 = true;
					break;
				}
			}
			if (f2)  break;
			if (sum < g && R.size() == 0) {
				f1 = true;
				break;
			}
		}
		if (f1)  continue;
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}
