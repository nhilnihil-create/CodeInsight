#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) x.begin(), x.end()
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	double x[n];
	string s[n];
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> s[i];
	}
	long double sum = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == "JPY") {
			sum += x[i];
		} else {
			sum += x[i] * 380000;
		}
	}
	cout << sum << "\n";
}

