#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(min(a,b)<=c&&max(a,b)>=c)
		printf("Yes\n");
	else printf("No\n");
}