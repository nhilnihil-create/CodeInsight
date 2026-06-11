#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1e15
#define MAX_Q 200001

long long N, Q;
string s;
vector<char> t(MAX_Q), d(MAX_Q);

bool C1(long long c) {
	ll now = c;
	for (long long i = 0; i < Q; i++) {
		if (s[now] == t[i]) {
			if (d[i] == 'L') now--; else now++;
		}
	}
	return now == 0;
}

bool C2(long long c) {
	ll now = c;
	for (long long i = 0; i < Q; i++) {
		if (s[now] == t[i]) {
			if (d[i] == 'L') now--; else now++;
		}
	}
	return now == N+1;
}

int main(){
	scanf("%lld",&N);
	scanf("%lld",&Q);
	cin >> s;
	s = "0"+s+"1";

	for (int i=0; i<Q; i++) {
		cin >> t[i];
		cin >> d[i];
	}

	long long lb = 1, ub = N+1;
	while (ub - lb > 1) {
		long long mid = (lb + ub) / 2;
		if (C1(mid)) lb = mid;
		else ub = mid;
	}

	ll res = N-lb;

	lb = 1; ub = N+1;
	while (ub - lb > 1) {
		long long mid = (lb + ub) / 2;
		if (!C2(mid)) lb = mid;
		else ub = mid;
	}

	res -= N-lb;

	cout << res << endl;
	return 0;

}
