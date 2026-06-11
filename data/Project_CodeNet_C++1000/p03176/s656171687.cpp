#include <bits/stdc++.h>
using namespace std;
long long bit[200002];
long long max(long long x, long long y) {
    return x > y ? x : y;
}
void update(int k, long long v) {
    for (int i = k + 1; i <= 200001; i += i & -i)
        bit[i] = max(bit[i], v);
}
long long query(int k) {
    long long res = 0;
    for (int i = k; i > 0; i -= i & -i)
        res = max(res, bit[i]);
    return res;
}
int N;
int H[200000], A[200000];;
long long dp[200001];
int main(){
	cin>>N;
	for (int i = 0; i < N; i++)  cin>>H[i];
	for (int i = 0; i < N; i++) cin>>A[i];
	for (int i = 0; i <= 200000; i++)
		dp[i] = -2e18;
    for (int i = 0; i <= 200001; i++)
        bit[i] = -2e18;
    dp[0] = 0;
    update(0, 0);
    for (int i = 0; i < N; i++) {
        dp[H[i]] = max(dp[H[i]], query(H[i]) + A[i]);
        update(H[i], dp[H[i]]);
    }
    cout<<query(N+1)<<endl;
    return 0;
}
