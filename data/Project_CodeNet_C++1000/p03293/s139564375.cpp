#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)

int main() {
	string s,t; cin >> s >> t;
	int n=s.size();
	rep(i,n) {
		if(s==t) {
			cout << "Yes" << endl;
			return 0;
		}
		s=s.back()+s.substr(0,n-1);
	}
	cout << "No" << endl;
}
