#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
	for(auto &a : A) cin >> a;

    ll ans = 0;
    ll left = 0, right = 0;
    ll xor_sum = 0, sum = 0;

	for(left=0;left<N;left++) {
		while(right < N) {
			if((sum + A[right]) == (xor_sum ^ A[right])) {
				sum += A[right];
				xor_sum ^= A[right];
				right++;
			} else {
				break;
			}
		}
		ans += (right - left);
		sum -= A[left];
		xor_sum -= A[left];
		if(left == right) right++;
	}

    cout << ans << endl;
}