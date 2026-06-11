#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[3003][3003];
string s,t;
int f(int curr_a,int curr_b){
	if(curr_a>=n || curr_b>=m) return 0;
	int&ret = dp[curr_a][curr_b];
	if(~ret) return ret;
	if(s[curr_a]==t[curr_b]){
		return ret = 1+f(curr_a+1,curr_b+1);
	}
	else{
		return ret = max(f(curr_a+1,curr_b),f(curr_a,curr_b+1));
	}
}
void backtracking(int mx,int curr_a,int curr_b){
	if(curr_a>=n || curr_b>=m) return;
	if(mx == 0) return;
	
	if(s[curr_a]==t[curr_b]){
		cout<<s[curr_a];
		backtracking(mx-1,curr_a+1,curr_b+1);
	}
	else{
		if(f(curr_a+1,curr_b)==mx) backtracking(mx,curr_a+1,curr_b);
		else backtracking(mx,curr_a,curr_b+1);
	}
}
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>s>>t;
	n = s.length();
	m = t.length();
	backtracking(f(0,0),0,0);
}