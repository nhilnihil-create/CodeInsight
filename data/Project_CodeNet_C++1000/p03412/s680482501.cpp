#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> A, vector<int> B, int N)
{
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	long long ans = 0;
	for(auto x: A)
		ans += B.end() - lower_bound(B.begin(), B.end(), N-x);
	return ans%2;
}
int A[202020], B[202020];
int main() {
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; ++i) scanf("%d", A+i);
	for(int i=0; i<N; ++i) scanf("%d", B+i);
	int ans = 0;
	for(int b=0; b<=29; ++b)
	{
		vector<int> X, Y, Z, W;
		int cnt1 = 0, cnt2 = 0;
		for(int i=0; i<N; ++i)
		{
			X.push_back(A[i]&((1<<b)-1));
			Y.push_back(B[i]&((1<<b)-1));
			if(A[i] & (1<<b)) ++cnt1;
			if(B[i] & (1<<b)) ++cnt2;
		}
		int c = solve(X, Y, (1<<b));
		if( (1LL*cnt1*(N-cnt2)+1LL*(N-cnt1)*(cnt2))%2 ) c = 1-c;
		ans += c<<b;
	}
	printf("%d\n", ans);
}