#include <iostream>
#include <cstring>
using namespace std;


int main() {
	
	int n;
	cin>>n;
	long long MAX = -10000000000;
	int a;
	long long sum = 0;
	while(n--)
	{
		cin>>a;
		
		if(a > MAX)
		{
			MAX = a;
		}
		sum+=a;
	}
	if(MAX % 2 == 0)
	{
		cout<<(sum-(MAX/2));
	}
	else
	{
		cout<<((double)sum-(MAX/2)+0.5-1);
	}
	return 0;
}