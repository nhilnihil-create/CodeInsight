#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int num;
	cin>>num;
	int coli[110]={0};
	int i;
	int ans=0;	
	for(i=0;i<num;i++)
	{
		cin>>coli[i];
	}
	for(i=1;i<num;i++)
	{
		if(coli[i-1]==coli[i])
		{
			coli[i]=10000+i;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
