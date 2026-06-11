#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	double ans = 0;
	for (int i = 1; i <= N; i++) {
		double p = 1./N;	
		int s = i;
		while (s < K) {
			s *= 2;
			p *= 0.5;
		}
		ans += p;
	}
	cout << setprecision(12) << ans << endl;

	return 0;
}
