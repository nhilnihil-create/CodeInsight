#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const long long mod = 1e9 + 7;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	string s;
	cin >> s;
	
	int len = s.size();	

	int cnt = 0;

	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'x') {
			cnt++;
		}
	}

	if (cnt <= 7) {
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
}