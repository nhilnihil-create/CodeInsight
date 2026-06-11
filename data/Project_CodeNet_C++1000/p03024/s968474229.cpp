#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	int ans = 0;
	rep(i, s.size()){
		if(s.at(i) == 'o') ans++;
	}
	if(ans + 15 - s.size() >= 8){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}