#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 105;

int n;
int a[N];

int main() {

	FAST;

	int a, b, c;
	cin >> a >> b >> c;
	cout << min(a * b, c) << '\n';
	return 0; 
}