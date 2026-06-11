#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int n,d,x;
	cin>>n>>d>>x;
	int a = 0;
	int k = 0;
	while(n--)
	{
		cin>>a;
		k++;
		int i = 1;
		while(i*a+1 <= d)
		{
			k++;
			i++;
		}
	}
	cout<<k+x;
	
	return 0;
}