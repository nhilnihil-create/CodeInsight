#include <bits/stdc++.h>
using namespace std;

void solve(long long H, long long W, long long N, vector<long long> X, vector<long long> Y){
	vector<set<long long>> O(W + 2);
	for(int i = 0; i <= W; ++i) {
		O[i].insert(H + 1);
	}
	for(int i = 0; i < N; ++i) {
		O[Y[i]].insert(X[i]);
	}

	long long res = H;
	long long r = 1, c = 1;
	for(; c <= W; ++c) {
		//cerr << r << "," << *O[c].upper_bound(r) << endl;
		res = min(res, *O[c].upper_bound(r) - 1);
		if(r < H && c < W) {
			do {
				++r;
			} while(O[c + 1].find(r) != O[c + 1].end());
		}
		if(r > H) break;
	}
	cout << res << endl;
}

int main(){	
	long long N;
	long long H;
	long long W;
	scanf("%lld",&H);
	scanf("%lld",&W);
	scanf("%lld",&N);
	vector<long long> X(N-1+1);
	vector<long long> Y(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&X[i]);
		scanf("%lld",&Y[i]);
	}
	solve(H, W, N, X, Y);
	return 0;
}

