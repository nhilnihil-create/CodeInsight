#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w;cin>>h>>w;
	string s[h+2];

	string t="";
	for(int i=0;i<w+2;i++){
		t+='x';
	}
	s[0]=t;
	s[h+1]=t;
	for(int i=1;i<=h;i++){
		cin>>s[i];
		s[i]+='x';
		s[i]='x'+s[i];
		// cout<<s[i]<<endl;
	}

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){

			if(s[i][j]!='.')continue;
			int cnt = 0;
			//check upper 3
			if( s[i-1][j-1]=='#' )cnt++;
			if( s[i-1][j+1]=='#' )cnt++;
			if( s[i-1][j]=='#' )cnt++;

			//check lower 3
			if( s[i+1][j-1]=='#' )cnt++;
			if( s[i+1][j+1]=='#' )cnt++;
			if( s[i+1][j]=='#' )cnt++;

			//check l,r
			if( s[i][j-1]=='#' )cnt++;
			if( s[i][j+1]=='#' )cnt++;

			s[i][j]=cnt+'0';
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cout<<s[i][j];
		}
		cout<<endl;
	}


}