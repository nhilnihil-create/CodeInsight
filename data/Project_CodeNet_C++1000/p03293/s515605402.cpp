#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s, t;

int main(void){
	cin >> s >> t;
	int n = s.size();
	rep(i, s.size()){
		char r;
		r = s[n-1];
		s = r+s.substr(0, n-1);
		if(s == t){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
