#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

signed main(){
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	bool f = true;
	for(int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
		f = f && A[i] == B[i];
	}

	if(f) {
		cout << 0 << endl;
		return 0;
	}

	int sum = 0, mn = (int)1e10;
	for(int i = 0; i < N; ++i) {
		sum += A[i];
		if(A[i] > B[i]) {
			mn = min(mn, B[i]);
		}
	}
	cout << sum - mn << endl;

	return 0;
}
