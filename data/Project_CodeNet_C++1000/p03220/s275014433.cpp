#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int N, T, A;
	cin >> N >> T >> A;

	vector<int> H(N);
	rep(i, N) cin >> H.at(i);
	double val = (T - A) / 0.006;
	// cout << val << endl;
	double vmin = INT64_MAX;
	int ans = 0;
	rep(i, N){
		double diff = val - H.at(i);
		if (diff < 0) diff *= -1;
		if (diff < vmin){
			vmin = diff;
			ans = i + 1;
		}
		// cout << diff << endl;
	}
	cout << ans << endl;
}