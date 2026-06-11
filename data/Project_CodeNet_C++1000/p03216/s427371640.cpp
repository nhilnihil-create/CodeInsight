#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <map>
#include <stack>
#include <cmath>
#define LL long long 
using namespace std; 
 
char c[1000005]; 
 
int main()
{
	int k,n,q;
	long long numm,numd,numc,numdm,nummc,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>c[i];
	scanf("%d",&q);
	while(q--)
	{
		numm=0,numd=0,numc==0,numdm=0,nummc=0,ans=0;
		scanf("%d",&k);
		for(int i=1;i<=n;i++)
		{
			if(i<=k)
			{
				if(c[i]=='D')
					numd++;
				if(c[i]=='M')
					numm++,numdm+=numd;
				if(c[i]=='C')
					numc++,nummc+=numm,ans+=numdm;
			}
			else
			{
//				cout<<i<<" "<<numd<<" "<<numm<<" "<<numdm<<endl;
				int x=i-k;
				if(c[x]=='D')
					numd--,numdm-=numm;
				if(c[x]=='M')
					numm--,nummc-=numc;
				if(c[x]=='C')
					numc--;
				if(c[i]=='D')
					numd++;
				if(c[i]=='M')
					numm++,numdm+=numd;
				if(c[i]=='C')
					numc++,nummc+=numm,ans+=numdm;
//				cout<<i<<" "<<numd<<" "<<numm<<" "<<numdm<<endl;
			}
		}
		cout<<ans<<endl;
	}
}