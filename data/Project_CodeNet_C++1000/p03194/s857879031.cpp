#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
typedef long long ll;
using namespace std;
#define int long long

//素数判定
inline bool IsPrime(int p) {
	if (p == 1) return false;
	for (int i = 2; i <= sqrt(p); i++) {
		if (p%i == 0) return false;
	}
	return true;
}

//10進数の自然数の桁数を返す
inline int GetDigit(int num) {
	return (int)log10(num) + 1;
}

//各位の和を返す
int GetDigitsSum(int num) {
	int N = 0;
	while (num > 0) {
		N += num % 10;
		num /= 10;
	}
	return N;
}

//互除法
ll gcd(ll a, ll b) {
	if (a < b) {
		return gcd(b, a);
	}
	else if (a%b) {
		return gcd(b, a%b);
	}
	else {
		return b;
	}
}

//異なるn個からr個の整数を取り出す組合せの数を求める
int combination(int n, int r) {
	if (r == 0 || n == r) {
		return 1;
	}
	else if (r == 1) {
		return n;
	}
	else {
		return combination(n - 1, r - 1) + combination(n - 1, r);
	}

}

//Ｏ(√n)
//素因数分解
map<int, int> prime_factor(int n) {
	map<int, int> res; // map[i]:=ｎを素因数分解したときiは何乗か。
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				res[i]++;
				n /= i;
			}
		}
	}
	if (n != 1)
		res[n] = 1;
	return res;
}

signed main() {
	int N, p;

	cin >> N >> p;
	if (N == 1) {
		cout << p << endl;
		return 0;
	}

	map<int, int> mp = prime_factor(p);

	int ans = 1;

	for (int i = 2; i * i <= p; i++) {
		if (mp[i] >= N) {
			ans *= pow(i,(mp[i]/N));
		}
	}

	cout << ans << endl;

	return 0;
}