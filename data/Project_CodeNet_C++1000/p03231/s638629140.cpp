#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::string s, t;
	std::cin >> n >> m >> s >> t;
	int g = gcd(n, m);
	for(int i = 0; i < g; i++) {
		if(s[i * (n / g)] != t[i * (m / g)]) {
			std::cout << "-1\n";
			return 0;
		}
	}
	std::cout << (long long) n / g * m << '\n';
}