#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int a[30];

int main() {
	string s;
  	char m;
	int n;

	vector<int> a(30);

	cin >> s;

	if (s=="zyxwvutsrqponmlkjihgfedcba") {
		cout << -1 << endl;
		return 0;
	}
	n=s.size();
	rep(i,n) a.at(s.at(i)-'a')++;
	if(n<26){
		cout << s ;
		rep(i,26) {
			if (a.at(i)==0){
				cout << char('a'+i) << endl;
				return 0;
			}
		}
	}else{
		m=s.at(25);
		for (int i=24; i>=0; i--){
			if(s.at(i)>s.at(i+1)) continue;
			if(i>0){
				rep(j, i) cout << s.at(j);
			}
			for (int j=25; j>=0; j--){
				if(s.at(i)>s.at(j)) continue;
				cout << s.at(j) << endl;
				return 0;
			}
		}
	}
}