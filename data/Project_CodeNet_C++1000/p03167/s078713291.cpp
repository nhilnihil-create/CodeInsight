#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

int main(){ _

	int h, w; cin >> h >> w;
	vector<vector<char>> grid(h, vector<char>(w));

	for(auto& v : grid) for(auto& c : v) cin >> c;

	vector<int> memo(w);
	memo[0] = 1;
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) {
			if(grid[i][j] == '#') memo[j] = 0;
			else memo[j] = (j ? (memo[j]+memo[j-1])%MOD : memo[j]);
		}	
	}
	
	cout << memo[w-1] << endl;

	return 0;
}
