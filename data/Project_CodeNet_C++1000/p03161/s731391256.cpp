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
	int t, k, n;
	cin >> n >> k;
	int h[n];
	for (int i = 0; i < n; i++)
	{cin >> h[i];}
	vector<int> a(n, INT_MAX);
	a[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < min(i + k + 1, n); j++)
		{
			a[j] = min(a[i] + abs(h[i] - h[j]), a[j]);
		}
	}
	cout << a[n - 1] << endl;
	return 0;
}