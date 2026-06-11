#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, a[N], b[N], ans, piv;

int over (vector<int> &A, vector<int> &B) {
	int C = 0, R = 0;
	for(int i=0,j=(int)B.size()-1;i<(int)A.size();i++) {
		while(j >= 0 && A[i] + B[j] >= piv) {
			C ^= 1;
			j--;
		}
		R ^= C;
	}
	return R;
}

void solve (int V) {
	vector<int> A[2], B[2];
	for(int i=1;i<=n;i++) {
		a[i] %= 2*V;
		A[!!(a[i]&V)].push_back(a[i]%V);
	}
	sort(A[0].begin(), A[0].end());
	sort(A[1].begin(), A[1].end());
	for(int i=1;i<=n;i++) {
		b[i] %= 2*V;
		B[!!(b[i]&V)].push_back(b[i]%V);
	}
	sort(B[0].begin(), B[0].end());
	sort(B[1].begin(), B[1].end());
	piv = V;
	ans += (over(A[0], B[0]) + over(A[1], B[1]) + 1ll*A[0].size()*B[1].size() - over(A[0], B[1]) + 1ll*A[1].size()*B[0].size() - over(A[1], B[0]))%2*V;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",&b[i]);
	}
	for(int i=29;i>=0;i--) {
		solve(1<<i);
	}
	printf("%d\n",ans);
}
