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
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	int N;
	cin >> N;
	vector<int>a(N), b(N);
	int suma = 0;
	int sumb = 0;
	rep(i, N)cin >> a[i];
	rep(i, N)suma += a[i];
	rep(i, N)cin >> b[i];
	rep(i, N)sumb += b[i];
	int num = sumb - suma; //操作回数
	int A = 0, B = 0;
	rep(i, N) {
		int sa = a[i] - b[i];
		if (sa > 0) {
			B += sa;
		}
		else if (sa < 0) {
			sa *= -1;
			if (sa & 1) {
				B++;
				sa++;
			}
			A += sa / 2;
		}
	}
	if (A <= num && B <= num && (num - A) * 2 == num - B)cout << "Yes" << endl;
	else cout << "No" << endl;
}