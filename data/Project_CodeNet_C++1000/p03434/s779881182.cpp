#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> a(N);
	rep(i, N)	std::cin >> a[i];
	std::sort(a.begin(), a.end());

	int A = 0;
	int B = 0;
	rep(i, N)
	{
		if((i % 2) != 0)
		{
			A += a[i];
		}
		else
		{
			B += a[i];
		}
	}	

	int ans = abs(A - B);
	std::cout << ans << std::endl;

    return 0;
}
