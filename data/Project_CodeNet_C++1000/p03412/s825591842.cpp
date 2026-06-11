#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

signed main(){
	int N;
	cin >> N;
	vector<int> a(N), b(N);
	for(int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < N; ++i){
		cin >> b[i];
	}
	int res = 0;
	for(int k = 1; k <= 30; ++k) {
		long long M = 1LL << k;
		vector<int> bb(N);
		for(int i = 0; i < N; ++i) {
			bb[i] = b[i] % M;
		}
		sort(ALL(bb));
		int cnt = 0;
		for(int i = 0; i < N; ++i) {
			int aa = a[i] % M;
			cnt += (lower_bound(ALL(bb), M - aa) - lower_bound(ALL(bb), M / 2 - aa))
				+ (lower_bound(ALL(bb), 2 * M - aa) - lower_bound(ALL(bb), 3 * M / 2 - aa));
		}
		res |= (cnt % 2) << (k-1);
	}
	cout << res << endl;
	return 0;
}
