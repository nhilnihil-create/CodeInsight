#include<bits/stdc++.h>
using namespace std;
int a,b;
char mp[105][105];
int main(){
	cin>>a>>b;
	for(int i=1;i<=50;i++){
		for(int j=1;j<=100;j++){
			mp[i][j]='.';
		}
	}
	for(int i=51;i<=100;i++){
		for(int j=1;j<=100;j++){
			mp[i][j]='#';
		}
	}
	a--;b--;
	for(int i=1;i<=49&&b;i+=2){
		for(int j=1;j<=100&&b;j++){
			if(mp[i-1][j]!='#'&&mp[i][j-1]!='#'){
				mp[i][j]='#';b--;
			}
		}
	}
	for(int i=52;i<=100&&a;i+=2){
		for(int j=1;j<=100&&a;j++){
			if(mp[i-1][j]!='.'&&mp[i][j-1]!='.'){
				mp[i][j]='.';a--;
			}
		}
	}
	puts("100 100");
	for(int i=1;i<=100;i++){
		puts(mp[i]+1);
	}
	return 0;
}
