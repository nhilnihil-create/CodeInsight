#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int ji = 100001;
int n;
int a[100005], b[100005], c;
inline int rd() {
	char ch = getchar();
	int s = 0, c = 1;
	while(!isdigit(ch)) {
		if(ch == '-') c = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		s = (s << 3) + (s << 1) + (ch ^ 48);
		ch = getchar();
	}
	return s * c;
}
int tr[200005];
void add(int x, int w) {
	for(; x <= 200000; x += x & (-x)) tr[x] += w;
}
int que(int x) {
	int ans = 0;
	for(; x; x -= x & (-x)) ans += tr[x];
	return ans;
}
int cal(int mid) {
	memset(tr, 0, sizeof(tr));
	int sum = 0, ans = 0, i;
	add(0 + ji, 1);
	for(i = 1; i <= n; ++i) {
		if(a[i] > mid) ++sum;
		if(a[i] <= mid) --sum;
		ans += que(ji + ji) - que(sum + ji);
		add(sum + ji, 1);
		//if(mid == 20) cout << ans << endl;
	}
	return ans;
}
main() {
	int i;
	n = rd();
	for(i = 1; i <= n; ++i) a[i] = b[i] = rd();
	sort(b + 1, b + 1 + n);
	c = n * (n + 1) / 2;
	c = c / 2 + 1;
	int l = 1, r = n, mid;
	while(l < r) {
		mid = l + r >> 1;//cout << b[mid] << " " << cal(b[mid]) << endl; 
 		if(cal(b[mid]) < c) l = mid + 1;
		else r = mid;
	} 
	cout << b[l];
	return 0;
}