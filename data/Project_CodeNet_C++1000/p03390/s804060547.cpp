#include<bits/stdc++.h>
#define LL long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
LL q,a,b;
void solve()
{
	cin>>a>>b;
	LL s=a*b,sq=0,ans=0;
	sq=(LL)sqrt((long double)s);
	if(sq*sq==s){
		ans=2*(sq-1);
		if(a!=b) ans--; 
	}
	else{
		if(sq*(sq+1)<s)
		  ans=2*sq-1;
		else
		  ans=2*(sq-1);
	}
	printf("%lld\n",ans);
}
int main()
{
	cin>>q;
	while(q--) solve();
	return 0;
}