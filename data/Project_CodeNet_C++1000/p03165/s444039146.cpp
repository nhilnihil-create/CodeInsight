#include<bits/stdc++.h>

using namespace std;

// Debug Code
#define deb1(x) cout<<#x<<'='<<x<<"\n"
#define deb2(x,y) cout<<#x<<'='<< x <<"|"<<#y<<'='<<y<< "\n"
#define deb3(x,y,z) cout<<#x<<"="<<a<<"|"<<#y<<"="<<b<<"|"<<#z<<"="<<c<<"\n"
#define deb1d(a,n) {for(int deb1d=0;deb1d<n;++deb1d){cout<<a[deb1d]<<" ";} cout<<"\n";}
#define deb2d(a,n,m) { for(int vari1=0;vari1<n;++vari1){for(int vari2=0;vari2<m;++vari2){cout<<#a<<"["<<vari1<<"]["<<vari2<<"]"<<"="<<a[vari1][vari2]<<' ';} cout<<"\n";} cout<<"\n";}
#define deb2dO(a,n,m) { for(int vari1=0;vari1<n;++vari1){for(int vari2=0;vari2<m;++vari2){cout<<a[vari1][vari2]<<' ';} cout<<"\n";} cout<<"\n";}
#define debCustom(s1,s2,len1,len2,a){cout<<"    ";deb1d(s2,len2); for(int debVari=0;debVari<len1;++debVari){cout<<s1[debVari]<<" ";deb1d(a[debVari],len2);}}

int main (){
	string s,t;
	cin>>s>>t;
	int l1=s.length()+1,l2=t.length()+1;
	vector<vector<int>>dp(l1+1, vector<int>(l2+1));
	vector<vector<pair<int,int>>>last(l1+1,vector<pair<int,int>>(l2+1));
	for(int i=1; i<=l1; ++i){
		for(int j=1; j<=l2; ++j){
			dp[i][j]=dp[i-1][j-1]+((s[i-1]==t[j-1])?1:0);
			last[i][j]={i-1,j-1};
			if(dp[i][j]<dp[i-1][j]){
				dp[i][j]=dp[i-1][j];
				last[i][j]={i-1,j};
			}
			if(dp[i][j]<dp[i][j-1]){
				dp[i][j]=dp[i][j-1];
				last[i][j]={i,j-1};
			}
		}
	}
	vector<char>cbuffer;
	int x=l1-1,y=l2-1;
	while(x!=0&&y!=0){
		if(s[x-1]==t[y-1]) cbuffer.push_back(s[x-1]);
		tie(x,y)=last[x][y];
	}
	reverse(cbuffer.begin(),cbuffer.end());
	for(char c : cbuffer) cout<<c;
	return 0;
}

