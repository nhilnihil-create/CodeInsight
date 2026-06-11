#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#define all(x) (x).begin(), (x).end()
#define xx first
#define yy second

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

class FenwickTree
{
public:
	FenwickTree(int k)
	{
		data.resize(k);
	}

	i64 sum(int n)
	{
		i64 ans = 0;

		while (n > 0)
		{
			ans += data[n];
			n -= (n & -n);
		}

		return ans;
	}

	void add(int n, i64 num)
	{
		while (n < data.size())
		{
			data[n] += num;
			n += (n & -n);
		}
	}

	int search(i64 k)
	{
		int lo = 0, hi = data.size() - 1;
		int ans = 0;

		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;

			i64 q = sum(mid);

			if (q >= k)
			{
				ans = mid;
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}

		return ans;
	}

private:
	vector<i64> data;
};

int main()
{
	i64 n;
	scanf("%lld", &n);

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	vector<int> sorted = arr;

	sort(all(sorted));


	int lo = 0, hi = n - 1;

	i64 idx = n * (n + 1) / 4 + 1;
	int ans = 0;

	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;

		//mid번째 보다 작은 값이 median인 구간의 개수를 센다
		vector<int> sum(n + 1);

		for (int i = 1; i <= n; i++)
		{
			if (arr[i - 1] >= sorted[mid])
				sum[i] = 1;
			else
				sum[i] = -1;
		}
		
		for (int i = 1; i <= n; i++)
			sum[i] += sum[i - 1];

		FenwickTree tree(2 * n + 1);

		i64 range = 0;

		// 임의의 l,r에 대해 sum[r] - sum[l-1] < 0 인 구간의 개수를 세야 함
		// sum[r] < sum[l-1]인 (l,r) 구간의 개수
		for (int i = 0; i <= n; i++)
		{
			tree.add(sum[i] + n, 1);
			auto c = tree.sum(sum[i] + n);

			//i+1개 중에서 c개는 내 이하 값
			range += i + 1 - c;
		}

		if (range > idx)
		{
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
			ans = mid;
		}
	}

	printf("%d\n", sorted[ans]);

	return 0;
}