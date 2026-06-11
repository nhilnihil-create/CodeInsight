#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void fuk() { puts("-1"); exit(0); }

const int MAXN = 100055;

map<ll, int> MP;

vector<pii> EV;

ll A[MAXN];
int B[MAXN], C[MAXN], dep[MAXN];

int N;

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		MP[A[i]] = i;
	}

	iota(B, B+N+1, 0); sort(B+1, B+N+1, [&](int a, int b) {
		return A[a] < A[b];
	});

	fill(C+1, C+N+1, 1);
	for(int oi = N, i; oi > 1; oi--) {
		i = B[oi];
		ll t = A[i] - N + C[i]*2;
		auto it = MP.find(t);
		if(MP.end() == it) fuk();
		int p = it -> second;
		if(p == i) fuk();
		C[p] += C[i];
		EV.eb(p, i);
	}

	{
		reverse(EV.begin(), EV.end());
		for(auto &e : EV)
			dep[e.second] = dep[e.first] + 1;

		ll sum = 0;
		for(int i = 1; i <= N; i++) sum += dep[i];
		if(sum != A[B[1]]) fuk();
	}

	for(auto &e : EV) printf("%d %d\n", e.first, e.second);
	return 0;
}