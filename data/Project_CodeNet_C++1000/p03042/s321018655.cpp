#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	string s;
	cin >> s;
	int u = (s[0] - '0') * 10 + s[1] - '0';
	int v = (s[2] - '0') * 10 + s[3] - '0';
	bool mmyy = false, yymm = false;
	if (1 <= u && u <= 12)mmyy = true;
	if (1 <= v && v <= 12)yymm = true;
	if (yymm && mmyy)cout << "AMBIGUOUS" << endl;
	else if (yymm)cout << "YYMM" << endl;
	else if (mmyy)cout << "MMYY" << endl;
	else cout << "NA" << endl;
}