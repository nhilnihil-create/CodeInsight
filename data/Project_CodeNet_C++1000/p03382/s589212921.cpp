#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

constexpr int MAXN = 100000;

int a[MAXN + 2];

int main() {
	int n;
	cin >> n;
	int x = 0, y = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(x < a[i])
			x = a[i];
	}
	for(int i = 0; i < n; i++)
		if(abs(y - x / 2) > abs(a[i] - x / 2))
			y = a[i];
	cout << x << ' ' << y << endl;
}
