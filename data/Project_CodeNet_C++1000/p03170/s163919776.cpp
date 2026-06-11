#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(int& i : v) cin >> i;

	vector<vector<int>> memo(2, vector<int>(k+1));
	
	memo[0][0] = memo[1][0] = 0;

	for(int i=0; i<=k; i++) {
		for(int j=0; j<2; j++) {
			for(auto u : v) if(i-u >= 0) memo[j][i] |= !memo[j^1][i-u];
		}
	}
	
	cout << (memo[0][k] ? "First" : "Second") << endl;
	
	return 0;
}
