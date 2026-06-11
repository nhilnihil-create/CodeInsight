#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int N,c=0;
	string s;
	cin >> N >> s;

	rep(i,N)
		c += (s.at(i) == 'R');
	cout << ((c*2>N) ? "Yes" : "No") << endl;
}