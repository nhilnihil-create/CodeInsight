#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
	int h,w;
	string s[100];
	cin>>h>>w;
	for(int i=0;i<h;i++){
		cin>>s[i];
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(s[i][j]=='#'){
				if(i==0 && j==0) 
					if(s[i+1][j]=='.' && s[i][j+1]=='.'){
						cout<<"No"<<endl;
						return(0);
					}
				if(i==0)
					if(s[i][j+1]=='.' && s[i][j-1]=='.' && s[i+1][j]=='.'){
						cout<<"No"<<endl;
						return(0);
					}
				if(j==0)
					if(s[i+1][j]=='.' && s[i-1][j]=='.' && s[i][j+1]=='.'){
						cout<<"No"<<endl;
						return(0);
					}
				if(i==h-1 && j==w-1)
					if(s[i-1][j]=='.' && s[i][j-1]=='.'){
						cout<<"No"<<endl;
						return(0);
					}
				if(i==h-1)
					if(s[i-1][j]=='.' && s[i][j+1]=='.' && s[i][j-1]=='.'){
						cout<<"No"<<endl;
						return(0);
					}
				if(j==w-1)
					if(s[i+1][j]=='.' && s[i-1][j]=='.' && s[i][j-1]=='.'){
						cout<<"No"<<endl;
						return(0);
					}
				if(i!=0 && i!=h-1 && j!=0 && j!=w-1)
					if(s[i+1][j]=='.' && s[i-1][j]=='.' && s[i][j+1]=='.' && s[i][j-1]=='.'){
						cout<<"No"<<endl;
						return(0);
					}
			}
		}
	}
	cout<<"Yes"<<endl;
    return(0);
}