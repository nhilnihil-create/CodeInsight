#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	string s;
	cin >> n >> s;
	vector<vector<int>> l(n, vector<int>(26));
	rep(i, 26){
		l.at(0).at(i) = 0;
	}
	l.at(0).at(s.at(0) - 'a')++;
	for(int i=1; i<n; i++){
		rep(j, 26) l.at(i).at(j) = l.at(i-1).at(j);
		l.at(i).at(s.at(i) - 'a')++;
	}
	int ma = 0;
	for(int i=1; i<n; i++){
		int sum = 0;
		rep(j, 26) if(l.at(i).at(j) > 0 && l.at(n-1).at(j) - l.at(i).at(j) > 0) sum++;
		if(ma < sum) ma = sum;
	}
	cout << ma << endl;
	return 0;
}
