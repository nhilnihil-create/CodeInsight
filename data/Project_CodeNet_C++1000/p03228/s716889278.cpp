#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int main()
{
	cin>>a>>b>>c;
	for(int s=0;s<c;s++)
	{
		if(s%2)
		{
			if(b%2)b--;
			a+=b/2,b/=2;
		}
		else
		{
			if(a%2)a--;
			b+=a/2,a/=2;
		}
	} 
	cout<<a<<" "<<b<<endl;
}