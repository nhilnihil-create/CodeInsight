#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define lP pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

ll N;
int a[100000], b[100001], l, r, k, c[222222];

void add(int x) {
	while (x < 222222) {
		++c[x];
		x += x&-x;
	}
}

int calc(int x) {
	int a = 0;
	while (x) {
		a += c[x];
		x -= x&-x;
	}
	return a;
}

int main() {
	cin >> N;
	for (int i = 0; i != N; ++i)
		cin >> a[i];
	r = intmax;
	while (l + 1 != r) {
		k = (l + r) / 2;
		for (int i = 0; i != N; ++i) {
			if (a[i] > k)
				b[i + 1] = 1;
			else
				b[i + 1] = -1;
		}
		for (int i = 0; i != 222222; ++i)
			c[i] = 0;
		b[0] = 111111;
		add(111111);
		ll c = 0;
		for (int i = 0; i != N; ++i) {
			b[i + 1] += b[i];
			c += calc(b[i + 1]);
			add(b[i + 1]);
		}
		if (c >= (N*(N + 1) / 2 + 1) / 2)
			l = k;
		else
			r = k;
	}
	cout << r << endl;
}