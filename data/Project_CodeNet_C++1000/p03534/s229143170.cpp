#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = n;i >= m;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 999999999
#define MINF -999999999
#define ALL(n) n.begin(),n.end()
#define MP make_pair
#define F first
#define S second

int main() {
	int c[3] = {};
	string s;
	cin >> s;
	REP(i, s.size()) c[s[i] - 'a']++;
	sort(c, c + 3);
	if(s.size() == 1) cout << "YES" << endl;
	else if (c[2] - c[0] > 1) cout << "NO" << endl;
	else cout << "YES" << endl;
}
