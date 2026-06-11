#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;string s;
	cin>>s;k=s.size();
	int cnt=15-k;
	for(int i=0;i<(int)s.size();i++) cnt+=s[i]=='o';
	if(cnt>=8) puts("YES");else puts("NO");
}