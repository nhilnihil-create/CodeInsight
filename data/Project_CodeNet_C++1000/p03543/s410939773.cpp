//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
#include<string>
using namespace std;
string s;
int c=0,f;
int main()
{
	cin>>s;
	
	if((s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3])||(s[1]==s[2]&&s[2]==s[3])||(s[0]==s[1]&&s[1]==s[2]))
		cout<<"Yes\n";
	else
		cout<<"No\n";

	return 0;
}
