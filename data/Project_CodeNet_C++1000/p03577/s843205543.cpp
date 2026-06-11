#include<bits/stdc++.h>
using namespace std;
char a[55];
int b;
int main()
{

	gets(a);
	b=strlen(a);
	int c;
	c=b-8;
	for (int i=0;i<c;i++)
	cout<<a[i];
	cout<<endl;
return 0;
}