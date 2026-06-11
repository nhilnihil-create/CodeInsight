#include <bits/stdc++.h>
using namespace std;

 
int main() {
	string s,t;
	cin >> s >> t;
	map<char,char> ma,ima;
	bool ok=true;
	for(int i=0;i<s.size();i++){
		char ss=s[i],tt=t[i];
		if(ma.count(ss)){
			if(ma[ss]!=tt) ok=false;
		}
		if(ima.count(tt)){
			if(ima[tt]!=ss) ok=false;
		}
		ma[ss] = tt;
		ima[tt] = ss;
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}
