#include <bits/stdc++.h>

using namespace std;

int main(){
	long long A, B, Q;
	cin >> Q;
	while(Q--){
		cin >> A >> B;
		long long C = A * B;
		long long lo = 1, hi = 2e9, ans = 0;
		while(lo <= hi){
			long long mid = (lo + hi) / 2LL;
			long long D = 0;
			long long M = mid / 2LL;

			for(long long i = M - 5; i <= M + 5; ++i){
				if(i < 1 || i > mid) continue;
				long long a = i;
				if(A <= a) ++a;
				long long b = mid - i + 1LL;
				if(B >= b) --b;
				D = max(D, a * b);
			}
			if(D < C) ans = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		if(ans >= min(A, B)) --ans;
		cout << ans << endl;
	}
	return 0;
}
