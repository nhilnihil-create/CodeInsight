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
 
int n,k;
long long a[1005]={0},b[1005]={0};  
vector <long long > v1;
vector <long long > v2;
 
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=b[i-1]+a[i];
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++)
			v1.push_back(b[j]-b[i]);
	long long ans=0;
	for(int i=62;i>=0;i--)
	{ 
		v2.clear();
		long long x=(LL)1<<i;
		for(int i=0;i<v1.size();i++)
			if(v1[i]&x)
				v2.push_back(v1[i]);
		if(v2.size()>=k)
			v1=v2,ans+=x;
	}
	cout<<ans<<endl;
}