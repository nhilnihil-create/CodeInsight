#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
#define rep(i, n) for(int i=0; i<(n); ++i)
using namespace std;
int main()
{
	int N; cin >> N;
	vector<int> A(N), B(N), C(N);
	rep(i, N) cin >> A[i];
	rep(i, N) cin >> B[i];
	rep(i, N) cin >> C[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	ll ans = 0;
	rep(i, N) {
		int a = lower_bound(A.begin(), A.end(), B[i]) - A.begin();	//a<bの数
		int c = C.end() - upper_bound(C.begin(), C.end(), B[i]);	//c>bの数
		ans += (ll)a * c;
	}
	cout << ans << endl;
}
