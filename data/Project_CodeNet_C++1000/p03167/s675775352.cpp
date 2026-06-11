#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int H, W;
	cin >> H >> W;

	char mp[H][W];

	vector<vector<int>> DP(H, vector<int>(W,0));

	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) cin >> mp[i][j];

	DP[0][0] = 1;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(mp[i][j] == '#') continue;
			if(i + 1 < H) DP[i+1][j] = (DP[i+1][j] + DP[i][j]) % MOD;
			if(j + 1 < W) DP[i][j+1] = (DP[i][j+1] + DP[i][j]) % MOD;
		}
	}

	if(mp[H-1][W-1] == '#') DP[H-1][W-1] = 0;

	cout << DP[H-1][W-1] << endl;

	return 0;
}
