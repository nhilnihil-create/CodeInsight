#include<bits/stdc++.h>
using namespace std;
char c[100005];
int main()
{
	scanf("%s",c+1);
	int lenc=strlen(c+1);
	int ans1=0,ans2=0;
	for(int i=1;i<=lenc;++i)
	{
		if(i%2==1)
		{
			if(c[i]=='0') 
			   ++ans1;
		}
		else
		{
		    if(c[i]=='1') 
			   ++ans1;
		}
		//cout<<i<<" "<<ans1<<endl;
	}
	for(int i=1;i<=lenc;++i)
	{
		if(i%2)
		{
			if(c[i]=='1') 
			    ++ans2;
		}
		else
		{
	         if(c[i]=='0') 
			     ++ans2;
	    }
		//cout<<i<<" "<<ans2<<endl;
	}
	//cout<<ans1<<" "<<ans2<<endl;
	int ans=min(ans1,ans2);
	printf("%d\n",ans);
	return 0;
}