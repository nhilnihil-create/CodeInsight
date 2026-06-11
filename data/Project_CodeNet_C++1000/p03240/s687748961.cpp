#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;

int main() {
	int n;
	cin >> n;
	vi x(n), y(n), h(n);

	rep(i, n)cin >> x[i] >> y[i] >> h[i];

	int ansx=INF, ansy=INF, ansh=INF;

	rep(cx, 101)rep(cy, 101) {
		
		bool dame = false;
		int H = 0;

		rep(i, n) {
			if (h[i] == 0)continue;

			int k = abs(x[i] - cx) + abs(y[i] - cy);

			if (H) {
				if (H == k + h[i])continue;
				else dame=true;
			}
			else H = k + h[i];
		}

		int mxh = INF;

		rep(i, n) {
			if (h[i])continue;

			int k = abs(x[i] - cx) + abs(y[i] - cy);

			if (H) {
				if (H > k)dame = true;
			}
			else mxh = min(mxh,k);
		}

		if (H == 0) {
			if (mxh == 0)dame = true;
			else H = mxh;
		}
		
		if (!dame) {
			ansx = cx;
			ansy = cy;
			ansh = H;
			break;
		}
	}

	cout << ansx << " " << ansy << " " << ansh << endl;

}