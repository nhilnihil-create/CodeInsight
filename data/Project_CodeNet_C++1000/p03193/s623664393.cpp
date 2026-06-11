#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
int main() {
	int N;
	ll H, W;
	cin >> N >> H >> W;
	vector<ll>A(N), B(N);
	ll ans = 0;
	rep(i, N) {
		cin >> A[i] >> B[i];
	}
	rep(i, N) {
		ans += min(A[i] / H, B[i] / W);
	}
	cout << ans << endl;
	return 0;
}
