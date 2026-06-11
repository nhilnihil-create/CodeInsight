#include<bits/stdc++.h>
using namespace std;
const int N=4000010;
bitset<N>b;
int n,x,s;
int main()
{
	scanf("%d",&n);
    b[0]=1;
	for (int i=1;i<=n;i++) {scanf("%d",&x); b=((b<<x)|b);s+=x;}	
	if (s&1) s=s/2+1; else s/=2; 
	for (int i=s;i<N;i++) if (b[i]) {
		printf("%d\n",i); break;
	}
}