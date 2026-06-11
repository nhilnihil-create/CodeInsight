#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
//const ll INF = 1LL<<60;
int INF = numeric_limits<int>::max();

int main(int, char**) {
	int h, w; cin >> h >> w;
	vector<vector<int>> dist(10, vector<int>(10, INF));
	vector<int> mind;
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			cin >> dist[i][j];
		}
	}
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			for (int k=0; k<10; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	ll ret = 0;
	for (int i=0; i<h*w; i++) {
		int a; cin >> a;
		if (a==-1) continue;
		else ret += dist[a][1];
	}
	cout << ret << endl;
	return 0;
}