#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;


int main() {

	string s;
	cin >> s;
	string ss = "";

	rep(i, s.size() - 1) {
		if (s[i] == 'B' && s[i + 1] == 'C') {
			ss.push_back('D');
			i++;
		}
		else ss.push_back(s[i]);
	}
	

	int a = 0;
	ll ans = 0;

	rep(i, ss.size()) {
		if (ss[i] != 'A' && ss[i] != 'D')a = 0;
		if (ss[i] == 'A')a++;
		if (ss[i] == 'D')ans += a;
	}

	cout << ans << endl;
}