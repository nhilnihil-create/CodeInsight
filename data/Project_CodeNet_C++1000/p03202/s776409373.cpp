#include <bits/stdc++.h>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define ll long long
//#define file
using namespace std;

int a[200001],n,i,j,k,l,L,R,Mid,tot;
map<int,int> mp;
map<int,int> :: iterator I;

bool pd(int t)
{
	mp.clear(),tot=0;
	fo(i,1,n)
	{
		if (a[i]>tot)
		mp[a[i]]=0,tot=a[i];
		else
		{
			I=mp.end(),--I;
			while ((I->first)>tot)
			mp.erase(I),I=mp.end(),--I;
			tot=a[i];
			
			j=a[i];
			while (j)
			{
				I=mp.find(j);
				if (I==mp.end()) {mp[j]=1;break;}
				else
				{
					if ((I->second)<t-1) {++mp[j];break;}
					else
					mp[j]=0,--j;
				}
			}
			if (!j) return 0;
		}
	}
	return 1;
}

int main()
{
	#ifdef file
	freopen("agc029C.in","r",stdin);
	#endif
	
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,2,n) if (a[i-1]>=a[i]) break;
	if (i>n) {printf("1\n");return 0;}
	
	L=2;R=n;
	while (L<R)
	{
		Mid=(L+R)/2;
		if (!pd(Mid))
		L=Mid+1; else R=Mid;
	}
	printf("%d\n",L);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}