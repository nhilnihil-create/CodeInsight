#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len=s.size(),k=len;
	for(int i=0;i+1<len;i++)
	if(s[i]!=s[i+1])
		k=min(k,max(i+1,len-i-1));
		cout<<k<<endl;
	return 0;
}