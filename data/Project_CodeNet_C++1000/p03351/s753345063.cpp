#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int INF = 1e8;

signed main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (abs(a - c) <= d) {
		cout << "Yes";
		return 0;
	}
	else if(abs(a - b) <= d && abs(b - c) <= d) {
		cout << "Yes";
		return 0;
	}
	cout << "No";
}