#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

vector<string> rotate(vector<string> C, int R) {
	if (R == 0) return C;

	int H = C.size();
	int W = C[0].length();

	if (R == 90) {
		vector<string> res(W);
		rep(i, W) {
			res[i] = "";
			rep(j, H) res[i] += C[H - 1 - j][i];
		}
		return res;
	}

	if (R == 180) {
		vector<string> res(H);
		rep(i, H) {
			res[i] = "";
			rep(j, W) res[i] += C[H - 1 - i][W - 1 - j];
		}
		return res;
	}

	if (R == 270) {
		vector<string> res(W);
		rep(i, W) {
			res[i] = "";
			rep(j, H) res[i] += C[j][W - 1 - i];
		}
		return res;
	}

	return C;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string> s(2);
	rep(i, 2) cin >> s[i];
	vector<string> rec = rotate(s, 180);
	if (rec == s) printf("%s\n", "YES");
	else printf("%s\n", "NO");
	return 0;
}
