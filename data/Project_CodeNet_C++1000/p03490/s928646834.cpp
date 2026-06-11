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
	bitset<16001> bit;
	bit[8000] = 1;
	for(auto d : a)	bit = (bit << d)|(bit >> d);
	if(b < 0) return 0; else return bit[b];
}
int main(){
	string s;
	int x, y;
	cin >> s; cin >> x >> y;
	vint X, Y;
	bool f = true;
	int start = 0;
	x += 8000, y += 8000;
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