#include<bits/stdc++.h>
using namespace std;
long long a,b,c,last,now; 
int main()
{
	cin>>a;
	for(int s=1;s<=a;s++)
	{
		cin>>b;
		if(b==last)now++;
		else
		{
			c+=now/2;
			now=1;
		}
		last=b;
	}
	cout<<now/2+c<<endl;
}