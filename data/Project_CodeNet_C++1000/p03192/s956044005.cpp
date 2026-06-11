#include<bits/stdc++.h>
using namespace std;
char a,b,c,d;
int ans=0;
int main()
{
	scanf("%c%c%c%c",&a,&b,&c,&d);
	if (a=='2') ans++;
	if (b=='2') ans++;
	if (c=='2') ans++;
	if (d=='2') ans++;
	printf("%d",ans);
	return 0;
} 