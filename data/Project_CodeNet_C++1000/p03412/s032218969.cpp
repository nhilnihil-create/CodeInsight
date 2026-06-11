#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 10;

typedef long long ll;

int n;
int A[MAXN], B[MAXN];
vector<int> abit[40], bbit[40];
int bcnt[60];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		for(int j=0;j<28;j++){
			if((A[i]>>j)&1) abit[j].push_back(A[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
		for(int j=0;j<28;j++){
			if((B[i]>>j)&1) bbit[j].push_back(B[i]);
		}
	}

	for(int b=0;b<30;b++) {
		int aocnt = abit[b].size();
		int azcnt = n - aocnt;
		
		int bocnt = bbit[b].size();
		int bzcnt = n - bocnt;
		
		azcnt &= 1, aocnt &= 1;
		bzcnt &= 1, bzcnt &= 1;

		bcnt[b] += azcnt*bocnt + bzcnt*aocnt;
		bcnt[b] &= 1;

		vector<int> C(n);
		for(int i=0;i<n;i++) {
			C[i] = B[i]%(1<<b);
		}
		sort(C.begin(), C.end());
		
		int carry = 0;
		for(int i=0;i<n;i++) {
			int lim = (1<<b) - (A[i]%(1<<b));

			int lbidx = lower_bound(C.begin(), C.end(), lim) - C.begin();
			carry += n-lbidx;
			carry &= 1;
		}

		bcnt[b] += carry;
		bcnt[b] &= 1;
	}

	int ans=0;
	for(int i=0;i<30;i++) {
		ans += (1<<i)*bcnt[i];
	}
	printf("%d", ans);
	return 0;
}