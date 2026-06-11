#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::vector<int> A;
	std::vector<int> B;
	std::vector<int> C;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		B.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		C.push_back(a);
	}
	long ans = 0;
	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	std::sort(C.begin(), C.end());
	for (int i = 0; i < n; i++)
	{
		long ans1;
		long ans2;
		std::vector<int>::iterator itr = std::lower_bound(A.begin(), A.end(), B.at(i));
		ans1= std::distance(A.begin(), itr);
		std::vector<int>::iterator itr2 = std::upper_bound(C.begin(), C.end(), B.at(i));
		ans2 = std::distance(itr2, C.end());
		ans += ans1 * ans2;
	}
	std::cout << ans << '\n';
}