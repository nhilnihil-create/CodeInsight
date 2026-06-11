#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007

ll s[3];
string ss;
int main() {
	cin >> ss;
	REP(i, ss.size()) {
		if (ss[i] == 'a')s[0]++;
		else if (ss[i] == 'b')s[1]++;
		else s[2]++;
	}
	sort(s, s + 3);
	cout << (abs(s[2] - s[0]) <= 1 ? "YES" : "NO") << endl;
}