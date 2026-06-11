#include <iostream>
#include <cstdio>
using namespace std;
long long n, nums[201000], sums, sumx, ans;
int main(){
	scanf("%lld", &n);
	for( int i = 1; i <= n; ++i )
		scanf("%lld", &nums[i]);
	long long r = 0;
	for( long long l = 1; l <= n; ++l ){
		while( r+1 <= n && sums+nums[r+1] == (sumx^nums[r+1]) ){
			++r;
			sums += nums[r];
			sumx ^= nums[r];
		}
		ans += r-l+1;
		sums -= nums[l];
		sumx ^= nums[l];
	}
	printf("%lld\n", ans);
	return 0;
}