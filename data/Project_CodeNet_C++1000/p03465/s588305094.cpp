#include <bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
int n,tot,x;
bitset<4000001>bs;
int main(){
	scanf("%d",&n),bs[0]=1;
	for(int i=1;i<=n;i++)scanf("%d",&x),tot+=x,bs|=(bs<<x);
	for(int i=(tot+1)/2;i<=4000000;i++)if(bs[i]){cout<<i<<"\n";return 0;}
}