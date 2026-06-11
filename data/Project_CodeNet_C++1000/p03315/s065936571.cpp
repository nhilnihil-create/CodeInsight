#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	int a=0;
	for(int i=0;i<4;i++){
		a+=s[i]=='+';
		a-=s[i]=='-';
	}
	cout<<a;
}