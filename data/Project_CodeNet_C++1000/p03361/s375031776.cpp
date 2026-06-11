#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int h,w; cin>>h>>w;
	vector<vector<string>> vv(h+2,vector<string>(w+2,"."));
	for(int i=1; i<=h; i++){
		string s; cin>>s;
		for(int j=1; j<=w; j++){
			vv[i][j]=s[j-1];
		}
	}
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			int cnt=0;
			if(vv[i][j]=="#"&&vv[i+1][j]=="#") cnt++;
			if(vv[i][j]=="#"&&vv[i-1][j]=="#") cnt++;
			if(vv[i][j]=="#"&&vv[i][j+1]=="#") cnt++;
			if(vv[i][j]=="#"&&vv[i][j-1]=="#") cnt++;
			if(vv[i][j]=="#"&&cnt==0){cout<<"No"<<endl; return 0;}
		}
	}
	cout<<"Yes"<<endl;
}