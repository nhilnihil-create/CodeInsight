#include<iostream>
#include<bitset>

using namespace std;

typedef long long ll;

int N, A[2010];

bitset<(2010 * 2010)> dp;

int main() {
	cin >> N;
	ll Sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i]; 
		Sum += A[i];
	}
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		dp |= (dp << A[i]);
	}
	
	for (ll ans = ((Sum + 1) / 2); ans <= 2000 * 2000; ans++) {
		if (dp[ans]) {
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}