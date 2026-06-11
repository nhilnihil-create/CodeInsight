#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int cnt = 0;
vector< vector<int> > lcs;

int LCS(string s1,string s2,int N,int M){
	if(N==0 || M==0){
		return 0;
	}
	if(lcs[N][M]!=-1){
		return lcs[N][M];
	}
	cnt++;
	if(s2[N-1]==s1[M-1]){
		lcs[N][M] = (1+LCS(s1,s2,N-1,M-1));
	}
	else{
		lcs[N][M] = max(LCS(s1,s2,N,M-1),LCS(s1,s2,N-1,M));	
	}
	return lcs[N][M];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s1,s2;
	cin>>s1>>s2;
	
	lcs.resize(s2.size()+1);
	for(int i=0;i<=s2.size();i++){
		lcs[i].resize(s1.size()+1,-1);
	}
	//long long final_ans = solveKnapsack(N,MAX);
	//int ans = LCS(s1,s2,s2.size(),s1.size());
	for(int i=0;i<=s1.size();i++){
		lcs[0][i] = 0;
	}
	for(int i=0;i<=s2.size();i++){
		lcs[i][0] = 0;
	}
	for(int i=1;i<=s2.size();i++){
		for(int j=1;j<=s1.size();j++){
			if(s1[j-1]==s2[i-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
			}
			else{
				lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
			}
		}
	}
	string lcsans = "";
	if(lcs[s2.size()][s1.size()]==0){
		cout<<"";
		return 0;
	}
	int i=s2.size(),j=s1.size();
	while(i>0 && j>0){
		if(s2[i-1] == s1[j-1]){

			lcsans = s1[j-1] + lcsans;
			i--;
			j--;
		}
		else if(lcs[i-1][j]>lcs[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	cout<<lcsans<<endl;
	return 0;
}