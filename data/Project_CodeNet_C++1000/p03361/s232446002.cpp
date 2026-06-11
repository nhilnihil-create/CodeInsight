#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int vx[] = { 1,0,-1,0 };
int vy[] = { 0,1,0,-1 };
int main()
{
	int H, W;
	cin >> H >> W;
	string S[51];
	for (int i = 0; i < H; i++) cin >> S[i];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#') {
				bool ok = false;
				for (int k = 0; k < 4; k++) {
					int nx = j + vx[k];
					int ny = i + vy[k];
					if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
					if (S[ny][nx] == '#') {
						ok = true;
						break;
					}
				}
				if (!ok) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
}