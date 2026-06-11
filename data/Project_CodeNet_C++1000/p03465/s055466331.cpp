#include <bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,s,x;
int main(){
bitset<N*N> f;
f[0]=1;
scanf("%d",&n); 
	for (register int i=1; i<=n; ++i)
	{
	scanf("%d",&x);
	f|=f<<x;
	s+=x;
	}
for (register int i=(s+1)/2; i<=s; ++i)
if (f[i]) {printf("%d\n",i); return 0;}
}