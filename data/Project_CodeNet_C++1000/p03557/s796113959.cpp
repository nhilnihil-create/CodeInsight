// C - Snuke Festival
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	cin.tie(0); ios::sync_with_stdio(false);

	int N; cin>>N;
	vector<int> A(N, 0), B(N, 0), C(N, 0);
	rep(i, N) cin>>A[i];
	rep(i, N) cin>>B[i];
	rep(i, N) cin>>C[i];
	sort(all(A));
	sort(all(C));
	int64_t ans = 0;
	for(int b:B){
		int ia = lower_bound(all(A), b) - A.begin();
		int ic = C.end() - upper_bound(all(C), b);
		ans += (int64_t)ia * ic;
	}
	cout<<ans<<endl;
}
