#include<bits/stdc++.h>
#define MAXN 200005 
using namespace std;

string s;
const int C = 8005;
int tx,ty;

bool dp[2][MAXN], temp[2][MAXN];

void work(int x, bool f){
	memset(temp, 0, sizeof(temp));
	for(int j=0;j<=2*C;j++){
		if(j-x>=0) temp[0][j] = dp[f][j-x];
		if(j+x<=2*C) temp[1][j] = dp[f][j+x];
	}
	
	for(int j=0;j<=2*C;j++){
		dp[f][j] = (temp[0][j] | temp[1][j]);
	}
}

int main(){
	
	cin>>s;
	cin>>tx>>ty;
	
	bool f = 0, f0 = 1;
	int cnt = 0;
	dp[1][C] = 1;
	for(int i=0;i<s.length();i++){
		if(s[i]=='F'){
			++cnt;
			if(i < s.length()-1) continue;
		}
		 
		if(f0){
			dp[f][cnt+C] = 1;
			f ^= 1;
			cnt = 0;
			f0 = 0;
		}
		else{
			work(cnt, f);
			f ^= 1;
			cnt = 0;
		}
	}
	
	if(dp[0][tx+C] && dp[1][ty+C]) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}