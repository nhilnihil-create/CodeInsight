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
const int INF = 1e15;
const int MOD = 1e9 + 7;
const double PI = 3.14159265358979323846;

signed main() {
	int input;
	map<int, int>m;
	vector<int>v;
	rep(i, 6) {
		cin >> input;
		m[input]++;
	}
	if (m.size() != 4) {
		cout << "NO";
		return 0;
	}
	for (auto i : m)v.push_back(i.second);
	sort(v.begin(), v.end());
	if (v[0] == 1 && v[1] == 1 && v[2] == 2 && v[3] == 2)cout << "YES";
	else cout << "NO";
}