#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN=1e5+10;

int A[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0, x;i<n;i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A+n);

	int lbidx = lower_bound(A, A+n-1, A[n-1]/2)-A;
	int c1 = A[lbidx];

	if(lbidx>0) lbidx--;
	int c2 = A[lbidx];
	
	int diff1 = min(abs(c1-A[n-1]/2), abs(c1 - (A[n-1]+1)/2));
	int diff2 = min(abs(c2-A[n-1]/2), abs(c2 - (A[n-1]+1)/2));
	
	int ans1 = A[n-1];
	int ans2 = A[0];
	if(diff1<diff2) {
		ans2 = c1;
	}
	else {
		ans2 = c2;
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}

