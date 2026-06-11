#include<bits/stdc++.h>
using namespace std;
int n;
int ans[105];
int cnt;
int main()
{
	scanf("%d",&n);
	if(!n)
	{
		cout<<0<<endl;
		return 0;
	}
	while(n)
	{
		
		++cnt;
		//cout<<n<<endl;
		if(abs(n)%(-2)) 
		{
			ans[cnt]=1;
			n--;
		}
		n/=-2;
        //cout<<ans[cnt]<<endl;
	}
	for(int i=cnt;i>=1;--i)
	   printf("%d",ans[i]);
	return 0;
}