#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int a[55];

int main(void)
{
	int n, k, i, j, p, q, ans = 0;

	scanf("%d %d" ,&n, &k);
	for (i = 0; i < n; i++)
		scanf("%d" ,&a[i]);

	for (i = 0; i <= min(n, k); i++)
		for (j = 0; i + j <= min(n, k); j++)
		{
			v.clear();
			for (p = 0; p < i; p++)
				v.push_back(a[p]);
			for (q = 0; q < j; q++)
				v.push_back(a[n - q - 1]);

			sort(v.begin(), v.end());

			int sum = 0;
			for (p = 0; p < v.size(); p++)
				sum += v[p];

			for (p = 0; p < min(k - i - j, (int)v.size()); p++)
				if (v[p] < 0)
					sum -= v[p];


			ans = max(ans, sum);
		}

	printf("%d" ,ans);
	return 0;
}