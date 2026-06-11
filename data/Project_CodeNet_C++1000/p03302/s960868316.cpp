#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include<stack>
#include <queue>
#include<map>
#include <set>
using namespace std;
#define int long long
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define loop(i,m,n) for(ll i=m;i<n;++i)
#define ggr getchar(); getchar();return 0;
#define pie 3.141592653589793238462643383279
#define INF 1000000007
int bin(int bina) {
	int ans = 0;
	for (int i = 0; bina > 0; i++)
	{
		ans = ans + (bina % 2)*pow(10, i);
		bina = bina / 2;
	}
	return ans;
}
bool prime(int n) {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int jo(int n) {
	int ans = 1;
	rep(i, n) {
		ans *= 2;
	}
	return ans;
}
signed main() {
	int a, b;
	cin >> a >> b;
	if (a + b == 15)cout << '+' << endl;
	else if (a*b == 15)cout << '*' << endl;
	else cout << 'x' << endl;
}