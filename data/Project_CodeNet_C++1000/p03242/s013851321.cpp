#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	int n=(int)s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='9')s[i]='1';
		else s[i]='9';
	}
	cout<<s;
}