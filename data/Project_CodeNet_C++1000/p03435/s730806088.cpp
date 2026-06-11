#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int main(void){
	vector<vector<int>> c(3, vector<int>(3));
	rep(i, 3){
		rep(j, 3){
			cin >> c[i][j];
		}
	}
	if(c[0][0]-c[0][1] == c[1][0]-c[1][1]
	&&c[1][0]-c[1][1]==c[2][0]-c[2][1]
	&&c[0][1]-c[0][2] == c[1][1]-c[1][2]
	&&c[1][1]-c[1][2] == c[2][1]-c[2][2]){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
