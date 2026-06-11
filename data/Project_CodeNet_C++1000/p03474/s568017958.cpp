#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	int a,b,x=0;
	string s;
	cin>>a>>b>>s;
	for(int i=0;i<a+b+1;i++){
		x+=s[i]=='-';
	}
	if(x>1 || s[a]!='-'){
		cout<<"No";
	}
	else cout<<"Yes";


	
	
}