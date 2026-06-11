#include <iostream>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;
	map<int, int> Nums;
	for (int i = 2; i <= N; i++) {
		int n = i;
		for (auto& p : Nums) {
			while (n % p.first == 0) {
				n /= p.first;
				p.second++;
			}
			if (n < p.first * p.first) break;
		}
		if (n > 1) Nums[n]++;
	}
	int two = 0, four = 0, fourteen = 0, twentyfour = 0, seventyfour = 0;
	for (auto p : Nums) {
		int& n = p.second;
		if (n >= 2 && n < 4) two++;
		if (n >= 4 && n < 14) four++;
		if (n >= 14 && n < 24) fourteen++;
		if (n >= 24 && n < 74) twentyfour++;
		if (n >= 74) seventyfour++;
	}
	int ans = 0;
	//1 1 75
	ans += seventyfour;
	//1 3 25 
	int n = twentyfour + seventyfour;
	ans += (two + four + fourteen) * n + n * (n - 1);
	//1 5 15
	n = fourteen + twentyfour + seventyfour;
	ans += four * n + n * (n - 1);
	//3 5 5
	n = four + fourteen + twentyfour + seventyfour;
	ans += two * n * (n - 1) / 2 + n * (n - 1) * (n - 2) / 2;
	cout << ans << endl;
}
