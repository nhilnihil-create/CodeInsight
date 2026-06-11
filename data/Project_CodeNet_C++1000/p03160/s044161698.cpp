#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
long long n, m = 1e9 + 7;
long long poww(long long a, long long b)
{
	if (b == 0) return 1;
	if (b == 1) return a % m;
	long long x = poww(a, b / 2) % m;
	x = (x * x) % m;
	if (b % 2 == 0) return (x) % m;
	else return (x * a) % m;
}
int gcd(int a, int b) {
	if (b == 0) return a;
	if (b == 1) return 1;
	return gcd(b, a % b);
}
int summ(long long n) {
	int sum = 0;
	for (int i = 0; i < 18; i++)
	{
		sum += n % 10; n /= 10;
		if (n == 0) break;
	}
	return sum;
}
vector<long long> fc;
long long fact(long long n) {
	fc[0] = 1; fc[1] = 1; fc[2] = 2;
	for (long long i = 3; i <= n; i++)
	{
		fc[i] = (i % m * fc[i - 1] % m) % m;
	}
	return fc[n] % m;
}
bool check(unordered_map<int, int>& map) {
	return 0;
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> n;
	int h[n];
	for (int i = 0; i < n; i++)
	{cin >> h[i];}
	int a[n]; a[0] = 0; a[1] = abs(h[1] - h[0]);
	for (int i = 2; i < n; i++)
	{
		a[i] = min(a[i - 2] + abs(h[i] - h[i - 2]), a[i - 1] + abs(h[i] - h[i - 1]));
	}
	cout << a[n - 1] << endl;
	return 0;
}