//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s,t;

	cin >> s >> t;

	bool	f;
	for(i=s.size()-t.size();i>=0;i--) {
		f = true;
		for(j=0;j<t.size();j++) {
			if (s[i+j]!='?' && s[i+j]!=t[j]) f = false; 
		}
		if (f) {
			for(j=0;j<t.size();j++) {
				if (s[i+j]=='?') s[i+j]=t[j]; 
			}
			break;
		}
	}
	if (f == false) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	for(i=0;i<s.size();i++) {
		if (s[i]=='?') s[i] = 'a';
	}
	//vector<ll>	aa(n);
	//for(i=0;i<n;i++) cin >> aa[i];
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));

	cout << s << endl;
	return 0;
}
