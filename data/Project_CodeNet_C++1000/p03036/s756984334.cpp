#include <iostream>

int main()
{
	int r, d, x;
	int ans;
	std::cin >> r >> d >> x;
	ans = x;
	for (int i = 0; i < 10; i++)
	{
		ans = r * ans - d;
		std::cout << ans << '\n';
	}
}