#include <iostream>
using namespace std;

int main() {
	long long n,h,w;
	cin>>n>>h>>w;
	long long Ok=0;
	while(n--)
	{
		long long a,b;
		cin>>a>>b;
		if(a>=h&&b>=w)
		{
			Ok++;
		}
		
	}
	cout<<Ok;
	
	
}