#include<iostream>
using namespace std;

int main()
{
	string s;cin>>s;
	int l = 1e9,r = s.length()-1;
	for(int i = 0; i<r; i++)if(s[i+1]!=s[i])l = min(l,max(i+1,r-i));
	cout<<(l==1e9?r+1:l);
	return 0;
}