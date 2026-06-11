#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int x[100005];
int main() {
	
	int n;
	cin>>n;
	long long sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin>>x[i];
		sum+=abs(x[i]-x[i-1]);
	}
	sum+=abs(x[n]);
	long long o = sum;
	for(int i = 1; i <= n; i++)
	{
		o = sum;
		o-=abs(x[i-1]-x[i]);
		o-=abs(x[i]-x[i+1]);
		o+=abs(x[i-1]-x[i+1]);
		cout<<o<<endl;
	}
	
	
	return 0;
}