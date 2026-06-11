#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

// 最大公約数を求める関数
long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {

	long long N, M;
	cin >> N >> M;

	string S, T;
	cin >> S;
	cin >> T;

	long long x = gcd(max(N, M), min(N, M));

	long long n = N / x;
	long long m = M / x;

	long long ans = -1;

	string str_n = "";
	string str_m = "";

	for (long long i = 0; i < N; i += n) {
		str_n += S.substr(i, 1);
	}

	for (long long i = 0; i < M; i += m) {
		str_m += T.substr(i, 1);
	}

	if (str_n == str_m) {
		ans = x * n * m;
	}

	cout << ans << endl;

	return 0;
}