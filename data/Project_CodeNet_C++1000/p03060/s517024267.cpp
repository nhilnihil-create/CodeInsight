#include <iostream>
using namespace std;
int x[1000], y [1000];
int main() {
	
	int n;
	cin>>n;
	int a = 0, b = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>x[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin>>y[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(x[i] >= y[i])
		{
			a+=x[i];
			b+=y[i];
		}
	}
	cout<<(a-b);
	return 0;
}