#include<bits/stdc++.h>
#define EM 100000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
using vint = vector<int>;
using vLL = vector<LL>;
using vvint = vector<vector<int>>;
using vvLL = vector<vector<LL>>;

bool solve(vint a, int b){
	set<int>	s, ss;
	s.insert(0);
	for(auto t : a){
		ss.clear();
		for(auto u : s){
			ss.insert(u+t);
			ss.insert(u-t);
		}
		s = ss;
	}
	return s.count(b);
}
int main(){
	string s;
	int x, y;
	cin >> s; cin >> x >> y;
	vint X, Y;
	bool f = true;
	int start = 0;
	while(start < s.size() && s[start] == 'F'){
		x--;
		start++;
	}
	for(int i = start;i < s.size();i++){
		int d = 0;
		while(s[i] == 'F'){
			d++;
			i++;
			if(i == s.size())	break;
		}
		if(d > 0) {if(f)	X.push_back(d); else Y.push_back(d);}
		f = !f;
	}
	bool ans = solve(X, x) && solve(Y, y);
	if(ans)	cout << "Yes" << endl;	else cout << "No" << endl;
}