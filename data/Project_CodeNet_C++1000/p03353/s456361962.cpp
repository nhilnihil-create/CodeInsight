// C - K-th Substring
#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)

int main(){
	string s; int k; cin>>s>>k;
	set<string> c;
	rp(i, 0, s.size())
		rp(j, i+1, i+6)
			c.insert(s.substr(i, j-i));
	for(auto x:c)
		if(--k == 0){ cout<< x <<"\n"; break; }
}
