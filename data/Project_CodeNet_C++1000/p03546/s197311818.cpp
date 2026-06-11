#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
vector<vector<int>>table(10, vector<int>(10));
vector<vector<int>>task(207, vector<int>(207));
int h, w;
void flyodwashall() {
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (table[i][j] > table[i][k] + table[k][j]) {
					table[i][j] = table[i][k] + table[k][j];
				}
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> h >> w;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> table[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> task[i][j];
		}
	}
	flyodwashall();
	// for (int i = 0; i < 10; i++) {
	// 	for (int j = 0; j < 10; j++) {
	// 		cout << table[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (task[i][j] == -1)continue;
			//cout << table[task[i][j]][1] << endl;
			ans += table[task[i][j]][1];
		}
	}
	cout << ans << endl;
}