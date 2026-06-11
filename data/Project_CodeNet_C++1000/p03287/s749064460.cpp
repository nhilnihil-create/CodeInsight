#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,ans,k;
map<int,int>n;
int main()
{
	cin>>a>>b;
	n[0]++;
	while(a--)
	{
		cin>>c;
		d=(d+c)%b;
		n[d]++;
	}
	for(map<int,int>::iterator it=n.begin();it!=n.end();it++)
	{
		k=it->second;
		ans+=(k*k-k)/2;
	}
	cout<<ans<<endl;
}