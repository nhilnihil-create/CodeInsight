#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
	string S;
	ll s=0,c=0;
	cin >> S;

	rep(i,S.size())
		if(S.at(i) == 'W') {
			s += i-c;
			++c;
		}

	cout << s << endl;
}