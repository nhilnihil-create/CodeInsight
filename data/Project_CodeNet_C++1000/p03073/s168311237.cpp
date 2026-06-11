#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int tmp=0;
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]){
			tmp++;
			if(s[i]=='0') s[i]='1';
			else s[i]='0';
		}
	}
	cout<<tmp<<endl;
	return 0;
} 
