#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
        int a,b,c;
        int sum;
	cin>>a>>b>>c;
	sum=b/a;
	if(sum>c)
                printf("%d\n",c);
        else
                printf("%d\n",sum);
        return 0;
}
