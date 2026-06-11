#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;
	int west[n+1]={0};
	int east[n+1]={0};
	for(int i=0; s[i]; i++){
		if(s[i]=='W') west[i+1] = 1;
		else east[i+1] = 1;
	}
	for(int i=1; i<=n; i++){
		west[i]+=west[i-1];
		east[i]+=east[i-1];
	}
	int minchange = n;
	for(int i=1; i<=n; i++){
		int change = west[i-1]+(east[n]-east[i]);
		minchange = min(minchange,change);
	}
	cout<<minchange;
}