#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;
//const int dx[] = {-1,0,1,0};
//const int dy[] = {0,-1,0,1};
const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)
int main() {
	int H, W; cin >> H >> W;
	vector<string> vs(H);
	rep(i, H) cin >> vs[i];
	rep(i, H) {
		rep(j, W) {
			if (vs[i][j] == '#') {
				cout << '#'; continue;
			}
			int num = 0;
			for (int k = 0; k < 8; k++) {
				int s = i+dy[k], t = j+dx[k];
				if (s < 0 || s >= H || t < 0 || t >= W) continue;
				if (vs[s][t] == '#') num++;
			}
			cout << num;
		}
		cout << endl;
	}
}