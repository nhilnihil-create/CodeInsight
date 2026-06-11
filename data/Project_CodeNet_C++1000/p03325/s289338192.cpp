#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
using namespace std;

int count(int a) {
	int ans = 0;
	while (a % 2 == 0) {
		ans += 1;
		a /= 2;
	}
	return ans;
}

int main() {

	int N;
	cin >> N;

	int a;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		ans += count(a);
	}

	cout << ans << endl;

	return 0;
}

