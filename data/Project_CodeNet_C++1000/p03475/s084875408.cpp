
// C - Special Trains

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N;
int C[500];
int S[500];
int F[500];

int get_arrival_time(int i, int t) {
	if (i == N-1) return t;

	int departure_time = max(S[i], F[i] * ((t-1) / F[i] + 1));
	int next_t = departure_time + C[i];

	return get_arrival_time(i+1, next_t);
}

int main() {
	cin >> N;

	for (int i=0; i<N-1; i++) {
		cin >> C[i] >> S[i] >> F[i];
	}

	for (int i=0; i<N; i++) {
		cout << get_arrival_time(i, 0) << endl;
	}

	return 0;
}