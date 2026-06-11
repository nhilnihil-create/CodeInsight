#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,n;
	scanf("%d%d%d",&n,&a,&b);
	if (abs(a-b)%2==0) printf("Alice");
	else printf("Borys");
	return 0;
}