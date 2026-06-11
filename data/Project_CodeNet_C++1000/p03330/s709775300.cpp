#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll INF = 100100100100;

int main() {
	ll N, C;
	cin >> N >> C;

	vector<vector<ll>> D(C, vector <ll> (C));
	for (int ii = 0; ii < C; ++ii){
		for (int jj = 0; jj < C; ++jj){
			cin >> D[ii][jj];
		}
	}

	//3クラスそれぞれに対してカウンタを計算
	vector<vector<ll>> cnt(3, vector <ll> (C));
	for (int ii = 0; ii < N; ++ii){
		for (int jj = 0; jj < N; ++jj){
			ll c;
			cin >> c;
			c--;
			ll idx = (ii+jj)%3;
			cnt[idx][c]++;
		}
	}

	ll ans = INF;
	for (int ii = 0; ii < C; ++ii){	//マス1の色
		for (int jj = 0; jj < C; ++jj){	//マス2の色
			for (int kk = 0; kk < C; ++kk){	//マス3の色
				if ( (ii==jj) || (jj==kk) || (kk==ii) ) continue;
				ll score = 0;
				for (int c = 0; c < C; ++c){
					score += cnt[0][c]*D[c][ii];
					score += cnt[1][c]*D[c][jj];
					score += cnt[2][c]*D[c][kk];
				}
				ans = min(ans, score);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
