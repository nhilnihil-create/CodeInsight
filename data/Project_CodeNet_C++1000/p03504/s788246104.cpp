#include <bits/stdc++.h>
using namespace std;

int imosu[30][100002];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, C; cin >> N >> C;
	for(int i = 0; i < N; i++){
		int s, t, c; cin >> s >> t >> c;
		imosu[c-1][s]++;
		imosu[c-1][t]--;
	}
	int ans = 0;
	for(int i = 1; i < 100001; i++){
		int cnt = 0, pre = 0;
		for(int j = 0; j < C; j++){
			imosu[j][i] += imosu[j][i-1];
			cnt += (imosu[j][i]||imosu[j][i-1]);
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}