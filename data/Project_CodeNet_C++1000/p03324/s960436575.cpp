#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int power_100(int d)
{
	int res = 1;
	for(int i = 0; i < d; i++) res *= 100;
	return res;
}

int main()
{
	int d, n;
	cin >> d >> n;
	cout << ((n == 100) ? power_100(d)*(n+1) : power_100(d)*n);
}
