#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	int N,l,ba=0,b=0,a=0,r=0;
	string S;
	cin >> N;

	rep(i,N) {
		cin >> S;
		l = S.size();

		rep(j,l-1)
			if(S.substr(j,2) == "AB")
				++r;

		if(S.at(0)=='B' && S.at(l-1)=='A')
			++ba;
		else if(S.at(0) == 'B')
			++b;
		else if(S.at(l-1) == 'A')
			++a;
	}

	cout << r+min(b,a)+ba+(-1)*(ba>0&&b+a==0) << endl;
}