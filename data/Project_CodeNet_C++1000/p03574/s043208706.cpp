#include <bits/stdc++.h>
using namespace std;
int n,m;
bool ch(int i,int j){
	return (i>=0&&i<n&&j>=0&&j<m);
}
int dx[8]={1,-1,1,-1,1,-1,0,0};
int dy[8]={1,-1,-1,1,0,0,-1,1};
int main(){
	cin>>n>>m;
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int num[n][m];
	memset(num,0,sizeof num);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int z=0;z<8;z++){
				if(ch(i+dx[z],j+dy[z])&&s[i+dx[z]][j+dy[z]]=='#'){
					num[i][j]++;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='.'){
				cout<<num[i][j];
			}else{
				cout<<s[i][j];
			}
		}cout<<endl;
	}
}