#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int a,b,n,t;
	cin>>a>>b;
	if(a+b==15) putchar('+');
	else if(a*b==15) putchar('*');
	else putchar('x');
	putchar('\n');
    return 0;
}