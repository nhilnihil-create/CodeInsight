#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& base) {
    for (T const& i : base) {
        out << i << ' ';
    }
    return out;
}
int main() {
    int H, W;
    cin >> H >> W;
    string grid[H];
    for(int i = 0; i < H; ++i){
    	cin >> grid[i];
    }
    int64_t DP[H][W];
    DP[H-1][W-1] = 1;
    const int64_t MOD = 1e9 + 7;
    for(int i = H-1; i >= 0; --i){
    	for(int j = W-1; j >= 0; --j){
    		if(grid[i][j] == '#') DP[i][j] = 0;
    		else if(i == H-1 && j == W-1) DP[i][j] = 1;
    		else if(i == H-1) DP[i][j] = DP[i][j+1];
    		else if(j == W-1) DP[i][j] = DP[i+1][j];
    		else DP[i][j] = (DP[i][j+1] + DP[i+1][j]) % MOD;
    	}
    }
    cout << DP[0][0] << endl;
}