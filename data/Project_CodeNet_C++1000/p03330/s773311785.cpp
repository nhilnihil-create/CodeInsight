#include<bits/stdc++.h>
using namespace std;
vector<int>dots[3];
int color[33][33];
int psum[3][33];
void init(int m,int c){
	for(int i=1; i<=c; i++){
		int cost = 0;
		for(int j=0; j<dots[m].size(); j++){
			cost+=color[dots[m][j]][i];
		}
		psum[m][i] = cost;
	}
}
int solve(int a,int b,int c){
	return psum[0][a]+psum[1][b]+psum[2][c];
}
int main(){
	int n,c;
	cin>>n>>c;
	for(int i=1; i<=c; i++){
		for(int j=1; j<=c; j++) cin>>color[i][j];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int num;
			cin>>num;
			dots[(i+j)%3].push_back(num);
		}
	}
	init(0,c);
	init(1,c);
	init(2,c);
	int mincost = numeric_limits<int>::max();
	for(int i=1; i<=c; i++){
		for(int j=1; j<=c; j++){
			for(int k=1; k<=c; k++){
				if(i==j || j==k || i==k) continue;
				mincost = min(solve(i,j,k),mincost);
			}
		}
	}
	cout<<mincost;
}

