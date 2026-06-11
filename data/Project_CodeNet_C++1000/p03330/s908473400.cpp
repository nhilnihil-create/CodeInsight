
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

const ll MOD_CONST = 1000000007;



int main()
{
	int n, maxC;
	cin >> n >> maxC;
	vector<vector<int>> d(maxC, vector<int>(maxC));
	for (int i = 0; i < maxC; i++) {
		for (int j = 0; j < maxC; j++) {
			cin >> d[i][j];
		}
	}



	vector<vector<int>> c(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
			c[i][j]--;
		}
	}


	vector<map<int, int>> maps(3, map<int, int>());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maps[(i + j) % 3][c[i][j]]++;
		}
	}

	ll ans = 10000000000;
	for (int i = 0; i < maxC; i++) {
		for (int j = 0; j < maxC; j++) {
			for (int k = 0; k < maxC; k++) {
				if (i != j && i != k && j != k) {
					ll cost = 0;
					
					for (auto it = maps[0].begin(); it != maps[0].end(); it++) {
						cost += d[it->first][i] * it->second;
					}
					for (auto it = maps[1].begin(); it != maps[1].end(); it++) {
						cost += d[it->first][j] * it->second;
					}
					for (auto it = maps[2].begin(); it != maps[2].end(); it++) {
						cost += d[it->first][k] * it->second;
					}
					if (cost < ans) {
						ans = cost;
					}
				}

			}
		}
	}

	cout << ans << endl;

}  

