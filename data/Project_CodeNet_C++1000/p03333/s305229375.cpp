#include<iostream>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

typedef long long ll;

ll N;
ll L[100000 + 10], R[100000 + 10];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> L[i] >> R[i];
	
	L[N] = 0, R[N] = 0;
	N++;

	sort(L, L + N, greater<ll>());
	sort(R, R + N);

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		if (L[i] >= R[i]) {
			ans += (L[i] - R[i]);
		}
	}
	cout << 2LL * ans << endl;
	return 0;
}