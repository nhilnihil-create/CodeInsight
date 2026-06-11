#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.length();i++)
		if(s[i]=='1') cout<<"9";
		else if(s[i]=='9') cout<<"1";
		else cout<<s[i];
	return 0;
}