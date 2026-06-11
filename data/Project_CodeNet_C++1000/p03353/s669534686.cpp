// C - K-th Substring
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	string s; int k; cin>>s>>k;
	vector<string> c;
	rep(i, s.size())
		rep(j, k) c.push_back(s.substr(i, j+1));
	sort(c.begin(), c.end());
	string pre = "";
	for(auto x:c){
		if(pre == x) continue;
		if(--k == 0){ cout<< x <<"\n"; break; }
		pre = x;
	}
}
