#include<bits/stdc++.h>
using namespace std;
bitset<4000000>f;
main(){
	int n,x,s=0;scanf("%d",&n);f[0]=1;for(int i=1;i<=n;i++)cin>>x,s+=x,f=f|(f<<x);
	for(int i=(s+1)/2;;i++)if(f[i])return cout<<i,0;
}
