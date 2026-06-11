#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	string S;
	cin >> S;
	set<char> t;

	rep(i,S.size())
		t.insert(S.at(i));
	
	if(t.size() < 26) {
		char x;
		for(char i='a'; i<='z'; ++i)
			if(!t.count(i)) {
				x = i;
				break;
			}
		cout << S << x;
	} else {
		int i = S.size()-1;
		char p=0, x='z';

		while(S.at(i) > p) {
			p = S.at(i--);
			if(i == -1) {
				cout << -1 << endl;
				return 0;
			}
		}

		rep(j,S.size()-i-1)
			if(S.at(i+1+j) > S.at(i))
				x = min(x, S.at(i+1+j));
		cout << S.substr(0,i) << x;
	}
	cout << endl;
}