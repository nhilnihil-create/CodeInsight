#include <bits/stdc++.h>

using namespace std;

bool ans = true;
string s;
int main(){
	cin >> s;
	if(s[s.length()-1] == '1') ans = false; // N must be 0
	if(s[0] == '0') ans = false;
	for(int i=0; i<s.length()-1; ++i) if(s[i] != s[s.length()-i-2]) ans = false;
	if(ans == false) cout << "-1";
	else{
		typedef pair<int,int> pi;
		vector<pi> edgelist;
		int cur = 1, nxt = 2;
		for(int i=0; i<s.length()-1; ++i){
			edgelist.push_back(pi(cur,nxt)); 
			if(s[i] == '1') cur = nxt;
			nxt++;
		}
		for(auto i : edgelist) cout << i.first << " " << i.second << "\n";
	}
}
