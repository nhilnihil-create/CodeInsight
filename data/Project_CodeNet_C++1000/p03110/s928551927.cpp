#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

int main() {
	
	cout<<fixed<<showpoint;
	cout<<setprecision(9);
	
	long double x;
	string s;
	int n;
	cin>>n;
	long double sum = 0;
	while(n--)
	{
		cin>>x>>s;
		if(s == "BTC")
		{
			sum+=(x*380000.0);
		}
		else
		{
			sum+=x;
		}
	}
	cout<<sum;
	
	return 0;
}