#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='x')sum++;
	if(sum<=7)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}