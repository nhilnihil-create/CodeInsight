#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	string t = "ACGT";
	vector<bool> ans(s.size());
	rep(i,s.size())rep(j,t.size()){
		if(s[i] == t[j]) ans[i] = true;
	}
	int counts = 0;
	int maxim = 0;
	rep(i,s.size()){
		if(ans[i]) {
			counts++;
			maxim = max(maxim,counts);
		}
		else counts = 0;
	}
	cout << maxim << endl;
}