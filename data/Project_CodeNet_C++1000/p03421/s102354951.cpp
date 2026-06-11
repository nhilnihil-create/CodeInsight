#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri(), a = ri(), b = ri();
	if (a + b > n + 1 || b < (n - 1) / a + 1) {
		puts("-1");
		return 0;
	}
	std::vector<int> res;
	int add = b - ((n - 1) / a + 1);
	while ((n - add - 1) / a + 1 + add < b) add++;
	for (int i = 0; i < n - add; i++) res.push_back(n - i - 1);
	for (int i = 0; i < (n - add) / a * a; i += a) std::reverse(res.begin() + i, res.begin() + i + a);
	std::reverse(res.begin() + (n - add) / a * a, res.end());
	for (int i = 0; i < add; i++) res.push_back(add - i - 1);
	for (auto i : res) std::cout << i + 1 << " ";
	
	std::cout << std::endl;
	
	return 0;
}
