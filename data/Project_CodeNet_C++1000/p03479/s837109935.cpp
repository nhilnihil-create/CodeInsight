#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x,y;
	cin>>x>>y;
	int k=1;
	long long t=x;
	while(t*2<=y)
	{
		t*=2;
		++k;
	}
	cout<<k<<endl;
	return 0;
}