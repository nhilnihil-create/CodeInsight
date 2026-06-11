#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>

#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0)return a;

	return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	char c[5][5];
	rep(i, 3)rep(j, 3) cin >> c[i][j];

	string ccc;
	rep(i, 3) ccc += c[i][i];
	cout << ccc << endl;

	return 0;
}