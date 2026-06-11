#include "bits/stdc++.h"
using namespace std;
long long INF = 1e18;
int main() {
	int A, B,Q;
	cin >> A >> B >> Q;
	vector<long long>S(A);
	for (int n = 0;n<A;++n) {
		cin >> S[n];
	}
	vector<long long>T(B);
	for (int n = 0;n<B;++n) {
		cin >> T[n];
	}
	S.push_back(INF); 
	S.push_back(-INF);	
	T.push_back(INF);
	T.push_back(-INF);
	sort(S.begin(),S.end()); 
	sort(T.begin(), T.end());
	for (int n = 0;n<Q;++n) {
		long long x;
		cin >> x;
		long long ans = INF;
		long long first;
		long long secound;
		for (int i = 0;i<2;++i) {
			int  l = upper_bound(S.begin(), S.end(), x) - S.begin();
			first = S[l - i]; 
			for (int j = 0;j<2;++j) {
				if (INF != abs(first)) {
					int  m = upper_bound(T.begin(), T.end(), first) - T.begin();
					secound = T[m - j];
					if (INF != abs(secound) ){
						ans = min(ans, abs(first - x) + abs(secound - first));
					}
				}
			}
		}
		for (int i = 0; i < 2; ++i) {
			int  l = upper_bound(T.begin(), T.end(), x) - T.begin();
			first = T[l - i];
			for (int j = 0; j < 2; ++j) {
				if (INF != abs(first)) {
					int  m = upper_bound(S.begin(), S.end(), first) - S.begin();
					secound = S[m - j];
					if(INF != abs(secound)) {
						ans = min(ans, abs(first - x) + abs(secound - first));
					}
				}
			}
		}
		cout << ans << endl;
	}
}
