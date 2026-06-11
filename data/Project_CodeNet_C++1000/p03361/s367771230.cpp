#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int h,w;cin>>h>>w;
	string s[h+2];

	string t = "";
	for(int i=0;i<w;i++)t+='x';

	s[0] = t;
	s[h+1] = t; 

	for(int i=1;i<=h;i++){
		cin>>s[i];
		s[i]+='x';
		s[i]='x'+s[i];
	}

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){

			if( s[i][j]=='#' ){
				bool good = 0;

				if( s[i-1][j]=='#' )good = true;
				if( s[i+1][j]=='#' )good = true;
				if( s[i][j+1]=='#' )good = true;
				if( s[i][j-1]=='#' )good = true;

				if( !good ){
					cout<<"No\n";
					return 0;
				}
			}
		}
	}
	cout<<"Yes\n";
	return 0;

	/*
	1. Check for output format
	2. CHeck for corner cases
	3. Compile and run given TC first
	*/

}