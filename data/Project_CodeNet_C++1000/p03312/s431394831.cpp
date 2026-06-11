#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#define INF 1000000000
#define MN 200005
using namespace std;
vector<long long> vec;
int n, k;
int a[MN];
long long left[MN][2], right[MN][2];
int main() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	int l = 1;
	long long lsum = a[1],rsum=0;
	for (i = 2; i <= n - 2; i++) {
		rsum += a[i];
		while (abs(rsum - lsum) > abs(rsum - a[l + 1] - (lsum + a[l+1]))) {
			l++; lsum += a[l]; rsum -= a[l];
		}
		left[i][0] = lsum; left[i][1] = rsum;
	}
	lsum = a[n]; rsum = 0;
	l = n;
	for (i = n-1; i >=3; i--) {
		rsum += a[i];
		while (abs(rsum - lsum) > abs(rsum - a[l - 1] - (lsum + a[l - 1]))) {
			l--; lsum += a[l]; rsum -= a[l];
		}
		right[i][0] = lsum; right[i][1] = rsum;
	}
	long long ans = -1;
	for (i = 2; i <= n - 2; i++) {
		vec.clear();
		vec.push_back(left[i][0]);
		vec.push_back(left[i][1]);
		vec.push_back(right[i + 1][0]);
		vec.push_back(right[i + 1][1]);
		sort(vec.begin(), vec.end());
		if (ans == -1) ans = vec[3] - vec[0];
		else ans = ans > (vec[3] - vec[0]) ? vec[3] - vec[0] : ans;
	}
	printf("%lld", ans);
	return 0;
}


