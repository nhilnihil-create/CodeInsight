#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
		string s;
		cin>>s;
		int x=0,y=0;
		for(int i=0;i<sz(s);i++){
			x+=s[i]=='1';
			y+=s[i]=='0';
		}
		cout<<min(x,y)*2;
}



