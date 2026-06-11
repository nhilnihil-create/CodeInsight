#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int mmin(int &a, int b) {
	a = min(a, b);
	return a;
}
long long mmin1(long long &a,long long b) {
	a = min(a, b);
	return a;
}
int mmax(int &a, int b) {
	a = max(a, b);
	return a;
}
long long mmax1(long long &a,long long b) {
	a = max(a, b);
	return a;
}
long long po(long long  a, int n,long long p) {
	if (n == 0) {
		return 1 % p;
	}
	long long x = po(a, n / 2, p);
	if (n % 2 == 0) {
		return (x*x) % p;
	}
	return (((x*x) % p)*a) % p;
}
long long inve(long long a, long long p) {
	return po(a, p - 2, p);
}
int main() {
	long long p = (1000 * 1000 * 1000) + 7;
	long long n;
	cin >> n;
	long long kai = 1;
	for (long long i = 1; i <= n; i++) {
		kai *= i;
		kai = kai % p;
	}
	vector<long long> ka(n);
	ka[0] = kai;
	long long sum = kai;
	for (long long i = 1; i < n; i++) {
		ka[i] = (kai*inve(i + 1, p)) % p;
		sum += ka[i];
		sum = sum % p;
	}
	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		long long a;
		cin >> a;
		ans += (a*sum) % p;
		ans = ans % p;
		if (i != n) {
			sum += ka[i];
			sum -= ka[n - i];
		}
		sum = (sum + p) % p;
	}
	cout << ans << endl;
	return 0;
}