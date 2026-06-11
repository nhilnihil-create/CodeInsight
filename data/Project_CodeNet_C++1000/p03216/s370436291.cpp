#include <bits/stdc++.h>
using namespace std;

void f(long long N, string S, long long Q, long long k) {
	long long res, a, d, m;
	res = a = d = m = 0;
	for(int i = 0; i < N; ++i) {
		if (i - k >= 0) {
			if (S[i - k] == 'D') {
				a -= m;
				--d;
			} else if (S[i - k] == 'M') {
				--m;
			}
		}
		if (S[i] == 'D') {
			++d;
		} else if(S[i] == 'M') {
			a += d;
			++m;
		} else if (S[i] == 'C'){
			res += a;
		}
	}
	cout << res << endl;
}

void solve(long long N, string S, long long Q, vector<long long> k){
	for(auto sk: k) {
		f(N, S, Q, sk);
	}
}

int main(){	
	string S;
	long long N;
	long long Q;
	scanf("%lld",&N);
	cin >> S;
	scanf("%lld",&Q);
	vector<long long> k((Q-1)-0+1);
	for(int i = 0 ; i <= (Q-1)-0 ; i++){
		scanf("%lld",&k[i]);
	}
	solve(N, S, Q, k);
	return 0;
}

