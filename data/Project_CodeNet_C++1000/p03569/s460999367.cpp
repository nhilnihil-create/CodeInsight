#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	string s0 = "";
	int sum = 0;
	vector<int> a(0);
	int xsum = 0;
	rep(i, s.size()){
		if(s.at(i) != 'x'){
			sum++;
			s0 += s.at(i);
			a.push_back(xsum);
			xsum = 0;
		}else{
			xsum++;
		}
	}
	a.push_back(xsum);
	int f = 0;
	rep(i, s0.size()){
		if(s0.at(i) != s0.at(s0.size()-1-i)) f = 1;
	}
	int ans = 0;
	rep(i, (a.size()+1)/2){
		if(a[i] != a[a.size()-1-i]) ans += abs(a[i] - a[a.size()-1-i]);
	}
	if(f == 0){
		cout << ans << endl;
	}else{
		cout << -1 << endl;
	}
	return 0;
}