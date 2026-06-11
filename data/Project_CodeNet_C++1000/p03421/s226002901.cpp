#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, A, B, cnt = 0, c = 0;
	cin >> N >> A >> B;
	if (A + B - 1 > N || N > A*B){
		cout << -1;
		return 0;
	}
	vector<int> seq[300005];
	for (int i = 1; i <= B; ++i){
		do{
			seq[i].push_back(++cnt);
			if (B - i >= N - cnt){
				c = 1;
			}
		} while(!c && seq[i].size() < A);

	}
	for (int i = B; i >= 1; --i){
		for (auto it : seq[i]){
			cout << it << ' ';
		}
	}
	cout << '\n' << flush;
	//for (int i = 0; i < 1e9; ++i){for (int j = 0; j < 1e9; ++j){}}
}