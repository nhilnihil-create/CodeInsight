#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mp make_pair
typedef long long ll;
using namespace std;

string s;
int x, y, cnt;
vector<int>vx, vy;
bool xy;
set<int>stx[5000], sty[5000];
int main() {
	cin >> s >> x >> y;
	xy = true;
	cnt = 0;
	lp(s.size()) {
		if (s[i] == 'T') {
			if (xy)
				vx.push_back(cnt);
			else vy.push_back(cnt);
			xy = !xy;
			cnt = 0;
		}
		else cnt++;
	}
	if (xy)
		vx.push_back(cnt);
	else vy.push_back(cnt);
	stx[0].insert(vx[0]);
	sty[0].insert(0);
	lp(vx.size() - 1) {
		for (auto it = stx[i].begin(); it != stx[i].end(); it++) {
			stx[i + 1].insert(*it + vx[i + 1]);
			stx[i + 1].insert(*it - vx[i + 1]);
		}
	}
	lp(vy.size()) {
		for (auto it = sty[i].begin(); it != sty[i].end(); it++) {
			sty[i + 1].insert(*it + vy[i]);
			sty[i + 1].insert(*it - vy[i]);
		}
	}
	if (stx[vx.size() - 1].find(x) != stx[vx.size() - 1].end() && sty[vy.size()].find(y) != sty[vy.size()].end())
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
