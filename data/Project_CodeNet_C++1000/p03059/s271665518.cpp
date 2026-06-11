#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 100005;

int n;
int a[N];

int main() {

	FAST;

	int a, b, t;
	cin >> a >> b >> t;
	cout << b * (t / a) << '\n';
	return 0;
}