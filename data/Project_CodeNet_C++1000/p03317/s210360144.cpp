#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

int main() 
{
	int N, K;
	std::cin >> N >> K;
	int ans = (N - 1) / (K - 1);
	if ((N - 1) % (K - 1) > 0) {
		ans++;
	}
	std::cout << ans << std::endl;
	return 0;
}