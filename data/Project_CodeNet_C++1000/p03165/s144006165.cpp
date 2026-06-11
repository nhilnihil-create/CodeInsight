#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	string s, t;
	cin>>s>>t;
	int m=s.size();
	int n=t.size();
//	cout<<"m"<<m<<"n"<<n<<endl;
	int lcs[m+1][n+1]={0};
	
	memset(lcs,0,sizeof(lcs));
//	for(int i=0;i<=m;i++) lcs[i][0]=0;
//	for(int i=0;i<=n;i++) lcs[0][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i-1]==t[j-1])
				{
				lcs[i][j]= 1+lcs[i-1][j-1];
			}
			else{
				lcs[i][j]= max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}
//	cout<<lcs[m][n];
	string ans;
	int i=m, j=n;
	while(i>=1&&j>=1){
				if(s[i-1]==t[j-1]){
				ans.push_back(s[i-1]);
				i--; j--;	
				}
			else {
				if(lcs[i-1][j]>lcs[i][j-1]){
					i--;
				}
				else j--;
			}
	}
	reverse(ans.begin(), ans.end());
	for(char u: ans){
		cout<<u;
	}
	cout<<endl;
	
//	cout<<lcs[m][n]<<endl;
	return 0;
}
