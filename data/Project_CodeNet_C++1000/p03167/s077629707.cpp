#include<bits/stdc++.h>
using namespace std;

int main(){
	int h,w;cin>>h>>w;
	long long dp[h][w];
	for(int i=0;i<h;i++) for(int j=0;j<w;j++) dp[i][j]=0;
	vector<string> v(h);
	for(int i=0;i<h;i++)cin>>v[i];
	dp[0][0]=1;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(v[i][j]=='.'){
				for(pair<int,int> k:{make_pair(i-1,j),make_pair(i,j-1)}){
					if(k.first>=0 && k.first<h){
						if(k.second>=0 && k.second<w){
							dp[i][j]=(dp[i][j] +dp[k.first][k.second])%1000000007;
						}

					}
				}
			}
		}
	}
	cout<<dp[h-1][w-1]<<endl;
}