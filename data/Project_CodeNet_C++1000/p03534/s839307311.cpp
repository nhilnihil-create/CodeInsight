#include <bits/stdc++.h>

using namespace std;

int ct[3];
char ss[200000];
int main()
{	
	scanf("%s",ss);
	int n=strlen(ss);
	for(int i=0;i<n;i++)
		ct[0]+=ss[i]=='a',
		ct[1]+=ss[i]=='b',
		ct[2]+=ss[i]=='c';
	sort(ct,ct+3);
	if(ct[2]-ct[0]>1) puts("NO");
	else puts("YES");
	return 0;
}