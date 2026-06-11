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
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	int N, A, B;
	cin >> N >> A >> B;
	int first = 0, second = 0, third = 0;
	rep(i, N) {
		int num;
		cin >> num;
		if (num <= A)first++;
		else if (num >= A + 1 && num <= B)second++;
		else if (num >= B + 1)third++;
	}
	int ans = min({ first,second,third });
	cout << ans << endl;
}