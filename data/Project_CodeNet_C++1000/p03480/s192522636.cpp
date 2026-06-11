#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char s[N];
int n,ans;
int main()
{
	scanf("%s",s+1);
	n=ans=strlen(s+1);
	for(int i=1;i<n;i++)
		if(s[i]!=s[i+1])
			ans=min(ans,max(i,n-i));
	printf("%d\n",ans);
	return 0;
}