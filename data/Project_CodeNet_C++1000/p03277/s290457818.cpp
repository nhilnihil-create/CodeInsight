#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+10;

const int base = 1e5+10;

int n;
int A[MAXN];
int small[MAXN];
ll fw[3*MAXN];

ll query(int i) {
	ll ret = 0;
	while(i>0) {
		ret += fw[i];
		i -= (i&-i);
	}
	return ret;
}

void update(int i, ll v) {
	while(i<=base+n) {
		fw[i] += v;
		i += (i&-i);
	}
}

// x보다 같거나 작은 median의 개수
ll calc(int x) {
	for(int i=1;i<=n;i++) {
		if(A[i]<=x) {
			small[i] = small[i-1] + 1;
		}
		else{
			small[i] = small[i-1] - 1;
		}
	}

	for(int i=0;i<=base+n;i++) {
		fw[i] = 0;
	}

	ll sum=0;
	update(base+0, 1ll);
	for(int R=1;R<=n;R++) {
		sum += query(base+small[R]-1);

		// printf("small[%d]:%d, ret:%lld\n", R, small[R], query(base+small[R]-1));
		update(base+small[R], 1ll);
	}

	// printf("x=%d, sum=%lld\n", x, sum);
	// puts("");
	return sum;
}

int main() {
	scanf("%d", &n);

	vector<int> cand;
	for(int i=1;i<=n;i++){
		scanf("%d", &A[i]);
		cand.push_back(A[i]);
	}

	sort(cand.begin(), cand.end());
	cand.erase(unique(cand.begin(), cand.end()), cand.end());

	int L = 0, R = cand.size()-1;
	while(L<R) {
		int M =(R+L)/2;
		ll ret = calc(cand[M]);

		if(ret>=(ll)n*(n+1)/2/2+1) R = M;
		else L = M+1;
	}

	printf("%d", cand[L]);

	// vector<int> mds;
	// for(int i=0;i<n;i++){		
	// 	for(int j=i;j<n;j++){
	// 		vector<int> tmp;

	// 		for(int k=i;k<=j;k++)
	// 			tmp.push_back(A[i]);
	// 		sort(tmp.begin(), tmp.end());
	// 		mds.push_back(tmp[(j-i+1)/2]);
	// 	}
	// }
	// sort(mds.begin(), mds.end());
	// printf("%d", mds[mds.size()/2]);
	return 0;
}