#include<bits/stdc++.h>
using namespace std;

int main(){

	int N,M;

	cin >> N >> M;

	//1000000007

	vector<vector<int>> DP(N,vector<int>(M,0));
	vector<string> G;

	for(int i=0;i<N;i++){
		string input;
		cin >> input;
		G.push_back(input);
		
	}



	DP[0][0] = 1;

	int row = DP.size();
	int col = DP[0].size();

	//init
	for(int j=1;j<col;j++){
		if(G[0][j]=='#'){
			DP[0][j] = 0;
		}else{
			// '.'

			DP[0][j] = DP[0][j-1];
		}
	}

	for(int i=1;i<row;i++){
		if(G[i][0]=='#'){
			DP[i][0] = 0;
		}else{
			// '.'

			DP[i][0] = DP[i-1][0];
		}
	}

	for(int i=1;i<row;i++){
		for(int j=1;j<col;j++){

			if(G[i][j]=='#'){
				DP[i][j]=0;
			}else{
				DP[i][j] = (DP[i-1][j]%1000000007+DP[i][j-1]%1000000007)%1000000007;
			}

		}
	}

	cout << DP[row-1][col-1] <<endl;

	return 0;

}