#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.length();
	int rem=15-n;
	for(int i=0;i<n;i++)
		if(s[i]=='o')rem++;
	if(rem>=8)printf("YES\n");
	else printf("NO\n");
	return 0;
}