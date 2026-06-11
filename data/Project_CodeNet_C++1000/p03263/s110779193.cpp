#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;
typedef tuple<int,int,int,int> tp;

int main(){
	int H,W;
	cin >> H >> W;
	vector<vector<int>> F(H,vector<int>(W));
	rep(i,H)rep(j,W)cin >> F[i][j];

	vector<tp> T;
	rep(i,H)rep(j,W-1){
		if(F[i][j]%2!=0){ F[i][j]--; F[i][j+1]++; T.push_back(make_tuple(i+1,j+1,i+1,j+2)); }
	}
	rep(i,H-1){
		if(F[i][W-1]%2 != 0){ F[i][W-1]--; F[i+1][W-1]++; T.push_back(make_tuple(i+1,W,i+2,W));}
	}

	cout << T.size() << endl;
	for(tp t : T){
		printf("%d %d %d %d\n",get<0>(t),get<1>(t),get<2>(t),get<3>(t));
	}

	return 0;
}