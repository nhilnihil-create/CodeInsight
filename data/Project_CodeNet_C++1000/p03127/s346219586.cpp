#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

int main(int argc, char *argv[]) {
	int n; cin >> n;

	int a; cin >> a;
	for (int i = 1; i < n; i++) {
		int b; cin >> b;
		a = gcd(a,b);
	}

	cout << a << endl;
	return 0;
}
