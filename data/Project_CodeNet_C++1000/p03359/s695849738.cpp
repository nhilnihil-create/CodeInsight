#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=2;i++)
	{
		if(a<=b)
    	{
        	cout<<a;
        	break;
    	}
    	if(a>b)
    	{
        	cout<<a-1;
        	break;
    	}
	}
    return 0;
}