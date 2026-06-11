#include<iostream>
#include<vector>
int main() {
	int a,b,c,x;
	int count = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> x;
	for (int i = 0; i <= a; i++) {
		if (500 * i > x)continue;
		for (int j = 0; j <= b; j++) {
			if (500 * i + 100 * j > x)continue;
			for (int k = 0; k<= c; k++) {
				if (500 * i + 100 * j + 50 * k == x) {
					count++;
					break;
				}
			}
		}
	}
	std::cout << count;
	return 0;
}