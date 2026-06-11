#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int counts = 0;
	vector<vector<int>> c(3, vector<int>(3));
	rep(i,3)rep(j,3) cin >> c[i][j];
	int maxim = 0;
	rep(i,3)rep(j,3) maxim = max(maxim,c[i][j]);
	vector<int> d(maxim);
	bool ok = false;
	rep(i,maxim +1)rep(j,maxim + 1){
		if(c[0][0] == i+j){
			int b1 = c[0][1] - j;
			int b2 = c[0][2] - j;
			int a1 = c[1][0] - i;
			int a2 = c[2][0] - i;
			if(c[1][1] == a1 + b1 && c[2][1] == a2 + b1 && c[1][2] == a1 + b2 && c[2][2] == a2 + b2) ok = true;
		}
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}