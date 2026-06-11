#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

const int inf=1<<29;
const int M=26;

int n;
string s;

int dp[200001][M+1];

int main(){
	cin>>s;
	n=s.size();
	for(int i=0;i<=n;i++) fill(dp[i],dp[i]+M+1,inf);
	map<int,int> m;
	int res=inf,S=0;
	dp[0][M]=0;
	m[0]=0;
	for(int i=0;i<n;i++){
		int c=s[i]-'a';
		S^=1<<c;
		dp[i+1][M]=dp[i][c];
		for(int j=0;j<M;j++){
			int T=S^(1<<j);
			if(m.find(T)!=m.end()){
				int I=m[T];
				for(int k=0;k<=M;k++) dp[i+1][j]=min(dp[i+1][j],dp[I][k]+(k!=M||I==0?1:0));
			}
		}
		m[S]=i+1;
	}
	for(int i=0;i<=M;i++) res=min(res,dp[n][i]);
	cout<<res<<endl;
}