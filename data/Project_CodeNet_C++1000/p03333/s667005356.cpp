#include <bits/stdc++.h>
using namespace std;

long long solve1(long long N, vector<long long> L, vector<long long> R){
	priority_queue<pair<long long,long long>> Q;
	priority_queue<pair<long long,long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> P;
	vector<bool> used(N);

	for(int i = 0; i < N; ++i) {
		Q.push(make_pair(L[i], i));
		P.push(make_pair(R[i], i));
	}

	long long res = 0, x = 0;
	for(int i = 0; !Q.empty() || !P.empty(); ++i) {
		if (i % 2 == 0) {
			while(!Q.empty() && (used[Q.top().second] || L[Q.top().second] <= x && x <= R[Q.top().second])) {
				Q.pop();
			}
			if(Q.empty()) continue;
			res += abs(Q.top().first - x);
			x = Q.top().first;
			used[Q.top().second] = true;
			Q.pop();
		} else {
			while(!P.empty() && (used[P.top().second] || L[P.top().second] <= x && x <= R[P.top().second])) {
				P.pop();
			}
			if(P.empty()) continue;
			res += abs(P.top().first - x);
			x = P.top().first;
			used[P.top().second] = true;
			P.pop();
		}
		//cerr << x << endl;
	}
	//cerr << endl;
	res += abs(x);

	return res;
}
void solve(long long N, vector<long long> L, vector<long long> R) {
	long long res = solve1(N, L, R);
	//cerr << res << endl;
	swap(L, R);
	for(int i = 0; i < N; ++i) {
		L[i] = -L[i];
		R[i] = -R[i];
	}
	res = max(res, solve1(N, L, R));
	cout << res << endl;
}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> L(N-1+1);
	vector<long long> R(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&L[i]);
		scanf("%lld",&R[i]);
	}
	solve(N, L, R);
	return 0;
}

