#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	int len = s.size();
	int ans = 1000000000;
	rep(i,len -2){
        string t;
		t.push_back(s[i]);
        t.push_back(s[i+1]);
        t.push_back(s[i+2]);
		int tnum = atoi(t.c_str());
		ans = min(ans,abs(753-tnum));
	}
	cout << ans << endl;
}