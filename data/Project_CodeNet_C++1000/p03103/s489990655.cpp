#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)
typedef long long ll;

int main(){
	int N, M;
	cin >> N >> M;

	vector<pair<ll, int>> D(N);
	rep(i, N)
		cin >> D.at(i).first >> D.at(i).second;
	sort(D.begin(), D.end());
	// rep(i, N) cout << D.at(i).first << " " << D.at(i).second << endl;;
	ll cost = 0;
	rep(i, N){
		if (M <= D.at(i).second){
			cost += M * D.at(i).first;
			break ;
		}
		M -= D.at(i).second;
		cost += D.at(i).second * D.at(i).first;
	}
	cout << cost << endl;
}