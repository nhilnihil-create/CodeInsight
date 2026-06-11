//ΔARC099D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const LL inf = 1e17;
int S(LL x){
	if(!x)
		return 0;
	return x%10+S(x/10);
}
LL a[111111];
DB p[111111];
int main()
{
	int n=0,i,j,f,k;
	LL x;
	cin>>k;
	for(i=1;i<=200;i=i+1){
		for(x=i;x<=inf;x=x*10)
			if(x-1)
				a[n++]=x-1;
	}
	sort(a,a+n);
	n=unique(a,a+n)-a;
	for(i=0;i<n;i=i+1)
		p[i]=(DB)a[i]/S(a[i]);
	for(i=0;i<n;i=i+1){
		f=1;
		for(j=i;j<n;j=j+1)
			if(p[i]>p[j])
				f=0;
		if(f&&k)
			k--,cout<<a[i]<<endl;
	}
	return 0;
}