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
	int f0 = 0, f1 = 0;
	rep(i,s.size()) {
		if ((s[i] - '0') ^ (i & 1))f0++;
		else f1++;
	}
	cout << min(f0, f1) << endl;

}