#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, A[2005], pref[2005];

bitset<4000005> num[2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i){
		cin >> A[i];
		pref[i] = pref[i-1] + A[i];
	}
	num[0][0] = 1;
	for (int i = 1; i <= N; ++i){
		num[i&1] = (num[(i-1)&1] | (num[(i-1)&1] << A[i]));
	}
	for (int i = (pref[N]+1)/2; i <= pref[N]; ++i){
		if (num[N&1][i]){
			cout << i << '\n';
			cout << flush;
			//for (int i = 0; i < 1e9; ++i){for (int j = 0; j < 1e9; ++j){}}
			return 0;
		}
	}
}