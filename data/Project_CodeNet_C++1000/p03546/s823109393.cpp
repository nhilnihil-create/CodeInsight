#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int A[210][210];
int d[10][10];
int main()
{
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> d[i][j];
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
		}
	}
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (A[i][j] != -1)ans += d[A[i][j]][1];
		}
	}
	cout << ans << endl;
}
