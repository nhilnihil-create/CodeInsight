#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

int main(){
	long long int n,sum=0;
	std::cin >> n;

	std::vector<long long int> v(n);
	std::vector<long long int> g(n);
	for (long long int& x : v) {
		std::cin >> x;
	}

	for (int i = 0; i < n; i++) {
		g[i]=v[i] - (i + 1);
	}

	std::sort(g.begin(), g.end());

	if (n % 2 == 0) {
		for (int i = 0; i < n; i++) {
			sum += abs(v[i] - ((g[n / 2 - 1] + g[n / 2]) / 2 + i + 1));
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			sum += abs(v[i] - (g[n / 2]+i+1));
		}
	}

	std::cout << sum << std::endl;

	return 0;
}