// C - K-th Substring
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	string s; int k; cin>>s>>k;
	set<string> c;
	rep(i, s.size())
		rep(j, k) c.insert(s.substr(i, j+1));
	for(auto x:c)
		if(--k == 0){ cout<< x <<"\n"; break; }
}
