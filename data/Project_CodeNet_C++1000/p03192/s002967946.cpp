#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define v(n) int n; cin>>n;
using namespace std;

int main() {
	char a;
	int o=0;
	rep(i, 4) {
		cin >> a;
		if (a == '2') o++;
	}
	cout << o << endl;
}