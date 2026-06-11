#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	string N;
	int c = 0;
	cin >> N;

	rep(i,4)
		c += (N.at(i)=='2');
	cout << c << endl;
}