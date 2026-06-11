#include<bits/stdc++.h>
using namespace std;
const int maxN = 18000 + 13;
string s;
int x, y, dp1[8013][maxN];
vector<int> vec[2];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cin >> x >> y;
    int cur = 0;
    int dir = 0;
    for (int i = 0; i < s.size(); i++) {
	if (s[i] == 'T') {
	    vec[dir].push_back(cur);
	    cur = 0;
	    dir ^= 1;
	}
	else
	    cur++;
    }
    vec[dir].push_back(cur);
    dp1[0][9000] = 1;
    for (int i = 0; i < vec[0].size(); i++)
	for (int j = 0; j < maxN; j++) {
	    if (j - vec[0][i] >= 0)
		dp1[i + 1][j] = dp1[i][j - vec[0][i]];
	    if (i != 0 && j + vec[0][i] < maxN)
		dp1[i + 1][j] |= dp1[i][j + vec[0][i]];
	}
    if (dp1[vec[0].size()][9000 + x]) {
	dp1[0][9000] = 1;
	for (int i = 0; i < vec[1].size(); i++) {
	    for (int j = 0; j < maxN; j++) {
		if (j - vec[1][i] >= 0)
		    dp1[i + 1][j] = dp1[i][j - vec[1][i]];
		if (j + vec[1][i] < maxN)
		    dp1[i + 1][j] |= dp1[i][j + vec[1][i]];
	    }
	}
	if (dp1[vec[1].size()][9000 + y])
	    cout << "Yes" << endl;
	else
	    cout << "No" << endl;
    }
    else
	cout << "No" << endl;
    
}
