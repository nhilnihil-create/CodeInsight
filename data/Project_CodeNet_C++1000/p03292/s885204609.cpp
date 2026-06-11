#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{

	int a,b,c;
	cin>>a>>b>>c;

	int val1=abs(a-c)+abs(b-c);
	int val2=abs(a-b)+abs(c-b);
	int val3=abs(c-a)+abs(b-a);

	cout<<min(val1,min(val2,val3))<<endl;
}