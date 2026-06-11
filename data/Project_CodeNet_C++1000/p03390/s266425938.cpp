#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

int sqrtb(int a) {
	int l = 1, u = (int)2e+9;
	while(u - l > 1) {
		int c = (l + u) / 2;
		if (c * c <= a) {
			l = c;
		} else {
			u = c;
		}
	}
	return l;
}

signed main(){
	int Q;
	cin >> Q;
	for(int i = 0; i < Q; ++i) {
		int A, B;
		cin >> A >> B;
		if(A > B) swap(A,B);
		if(B == 1) {
			cout << 0 << endl;
			continue;
		}
		int M = A * B - 1;
		int L = (int)sqrtb(M);
		int t = 2 * L - (M / L == L);
		if(A <= L) {
			--t;
		}
		cout << t << endl;
	}
	return 0;
}
