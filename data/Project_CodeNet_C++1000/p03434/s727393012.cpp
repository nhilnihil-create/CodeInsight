#include <iostream>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	int a[100];
	for (int i=0; i<N; i++) std::cin >> a[i];
	std::sort(a, a+N, std::greater<int>());
	int res = 0;
	for (int i=0; i<N; i+=2) res += a[i];
	for (int i=1; i<N; i+=2) res -= a[i];
	std::cout << res << std::endl;
	return 0;
}
