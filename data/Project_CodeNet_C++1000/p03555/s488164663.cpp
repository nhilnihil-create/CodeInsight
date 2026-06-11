#include <bits/stdc++.h>
using namespace std;

string s[200];
int n, m;

int main(){
	for(int i=1; i<=2; i++){
		cin>>s[i];
		s[i]='0'+s[i];
	}
	
	for(int i=1; i<=3; i++){
		if(s[1][4-i]!=s[2][i]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	cout<<"YES"<<endl;
	return 0;
}
