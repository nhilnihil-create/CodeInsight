#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int nums[100000];

int main(void)
{
	scanf("%d", &N);
	for (int n = 0; n < N; ++n)
		scanf("%d", nums + n);
	sort(nums, nums + N);
	long long minabs;
	int minidx = -1;
	for (int n = 0; n < N - 1; ++n)
	{
		long long nv = abs((long long)nums[N - 1] - 2 * ((long long)nums[n]));
		if (minidx == -1 || minabs > nv)
		{
			minabs = nv;
			minidx = n;
		}
	}
	printf("%d %d", nums[N - 1], nums[minidx]);
	return 0;
}