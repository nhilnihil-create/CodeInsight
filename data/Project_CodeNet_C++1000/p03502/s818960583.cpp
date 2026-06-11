#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
 
int main() {
	int a,n;
	int i;
	int sum=0;

	cin >> a;
	n = a;
	for (i = 100000000; i > 0; i /= 10)
	{
		sum += n / i;
		n -= n / i * i;
	}
	if (a % sum == 0)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}
