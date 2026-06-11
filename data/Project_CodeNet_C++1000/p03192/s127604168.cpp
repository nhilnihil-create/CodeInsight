#include <iostream>
using namespace std;
int main()
{
	int n, i, count=0;
	cin>>n;
	int arr[4];
	for(i=0; i<4; i++)
	{	
		{
		arr[i] =  n%10;
		n = n/10;
		}
	}
	for(i=0; i<4; i++)
	{
		if (arr[i] == 2)
		{
			count++;
		}
	}
	
	cout<<count<<endl;
	
	return 0;
	
}

