#include<bits/stdc++.h>
using namespace std;
long long a,b,c[105],ans,kiki;
int main()
{
	cin>>a>>b;
	for(int s=0;s<a;s++)
	{
		cin>>c[s];
	}
	sort(c,c+a);
	for(int s=0;s<a;s++)
	{
		if(b-c[s]>=0)b-=c[s],ans++;
		else 
		{
			kiki=1;break;
		}
	}
	if(kiki==0&&b>0)ans--;
	cout<<ans<<endl;
}