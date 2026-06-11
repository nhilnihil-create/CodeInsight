#include<bits/stdc++.h>                          
using namespace std;
int t[100];
string s;
int main(){
	cin>>s;
	for(int i=0;i<3;i++)
	    t[s[i]]++;
	for(int i='a';i<='c';i++)
	    if(t[i]!=1) {cout<<"No";return 0;}
	cout<<"Yes";
	return 0;
}