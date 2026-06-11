#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
int main()
{
	long a,b,k;
	cin>>a>>b>>k;
	for(int i=0;i<k/2;i++)
	{
		a-=a%2;
		b+=a/2;
		a/=2;
		b-=b%2;
		a+=b/2;
		b/=2;
	}
	if(k%2)a-=a%2,b+=a/2,a/=2;
	cout<<a<<" "<<b<<endl;
}