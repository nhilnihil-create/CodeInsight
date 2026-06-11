#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[3002][3002];
string ans;

void lcs(string a, string b, int n, int m){

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0)
				dp[i][j] = 0;
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}

}

void print(string a,string b,int n, int m){
	int i=n,j=m;
	while(i!=0 && j!=0){
		if(a[i-1]==b[j-1]){
			ans.push_back(a[i-1]);
			i--;j--;
		} else{
			if(dp[i-1][j]>dp[i][j-1]){
				i--;
			} else{
				j--;
			}
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
}



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    lcs(s,t,s.size(),t.size());
    print(s,t,s.size(),t.size());
    return 0;
}
