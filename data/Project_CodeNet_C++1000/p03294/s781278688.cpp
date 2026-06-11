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

int main() {

	int N;
	cin >> N;

	int ans = 0;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		a--;
		ans += a;
	}

	cout << ans << endl;

	return 0;
}

