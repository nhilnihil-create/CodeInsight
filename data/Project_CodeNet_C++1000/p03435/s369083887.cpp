#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	vector<vector<int>> a(3,vector<int>(3));
	vector<int> x(3);
	vector<int> y(3);
	rep(i, 3){
		rep(j, 3) cin >> a.at(i).at(j);
	}

	x.at(0) = 0;
	rep(i, 3) y.at(i) = a.at(0).at(i) - x.at(0);
	for(int i = 0; i < 3; i++) x.at(i) = a.at(i).at(0)-y.at(0);

	bool res = true;
	rep(i, 3){
		rep(j, 3){
			if(a.at(i).at(j) != x.at(i)+y.at(j))
				res = false;
		}
	}
	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;
}
