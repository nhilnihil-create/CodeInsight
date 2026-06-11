#include<bits/stdc++.h> 
using namespace std;


int main() {
	int N;
    cin>>N;
    double dp[N+1][N+1][N+1];
    memset(dp,0.0,sizeof(dp));
    vector<int> count(4,0);
    for (int i=0;i<N;i++){
    	int x;
    	cin>>x;
    	count[x]++;
    }
    int max_ones=count[1]+count[2]+count[3];
    int max_twos=count[2]+count[3];
    int max_threes=count[3];
    int i=0,j=0,k=0;
    for (int c=0;c<=max_threes;c++){
    	for(int b=0;b<=max_twos-c;b++){
    		for (int a=0;a<=max_ones-b-c;a++){
    			if (a+b+c==0) continue;
    			double n=a+b+c;
    			dp[a][b][c]=(double)N/n;
    			if (a>0) {
    				dp[a][b][c]=dp[a][b][c]+(dp[a-1][b][c]*(double)a)/n;
    			}
    			if (b>0) {
    				dp[a][b][c]=dp[a][b][c]+(dp[a+1][b-1][c]*(double)b)/n;
    			}
    			if (c>0) { 
    				dp[a][b][c]=dp[a][b][c]+(dp[a][b+1][c-1]*(double)c)/n;
    			}
    			i=a,j=b,k=c;
       		}
    	}
    }
	cout<< setprecision(16)<<dp[i][j][k]<<endl;
    return 0; 
}
