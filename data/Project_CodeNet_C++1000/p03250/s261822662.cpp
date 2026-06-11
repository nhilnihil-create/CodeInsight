//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int maxn = ~0x3f3f3f3f, a[4];

int main()
{
    cin>>a[1]>>a[2]>>a[3];
    for(int i=1;i<=3;i++)
    	for(int j=1;j<=3;j++)
        	for(int k=1;k<=3;k++)
        		if(i != j && i != k && j != k)
            		maxn = max(maxn, a[i]+a[j]*10+a[k]);
    cout<<maxn<<endl;
    return 0;
}