#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, A[200000], B[200000];
	cin >> N;
	for(int i=0; i<N; i++) cin >> A[i] >> B[i];
	int64_t S = accumulate(A, A+N, 0LL);

	const int INF = 2e9;
	int mn = INF;
	for(int i=0; i<N; i++) if(A[i] > B[i]) mn = min(mn, B[i]);

	int64_t ans = (mn == INF ? 0 : S - mn);
	cout << ans << endl;
    return 0;
}
