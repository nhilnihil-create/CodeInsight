#include <iostream>
#include <cstdio>
using namespace std;
int n, k, nums[101000], ans = 0x3f3f3f3f;
int f[101000];
bool vis[101000];
inline int abs( int r ){
	return r < 0 ? -r : r;
}
int main(){
	scanf("%d%d", &n, &k);
	nums[0] = 0x3f3f3f3f;
	for( int i = 1; i <= n; ++i )
		scanf("%d", &nums[i]);
	for( int i = 1; i+k-1 <= n; ++i ){
		int y = nums[i+k-1] - nums[i], x = min(abs(nums[i]), abs(nums[i+k-1]));
		ans = min(ans, x+y);
	}
	printf("%d\n", ans);
	return 0;
}