#include<bits/stdc++.h>
using namespace std;
int a,b,q; 
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		long long mul=(long long)a*b,res,ans;
		res=sqrt(mul);
		ans=res*2-1;
		if(res*res==mul&&(a^b)) --ans;
		if(res*(res+1)>=mul) --ans;
		cout<<ans<<endl; 
	}
}