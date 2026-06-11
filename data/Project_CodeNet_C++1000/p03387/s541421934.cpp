#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	int nums[3] = { a, b, c };
	sort(nums, nums + 3);

	int diff = nums[2] - nums[1];
	nums[0] += diff;

	int ans;
	if ((nums[2] - nums[0]) % 2 == 1) ans = diff + (nums[2] - nums[0] + 1) / 2 + 1;
	else ans = diff + (nums[2] - nums[0]) / 2;

	printf("%d\n", ans);

	return 0;
}