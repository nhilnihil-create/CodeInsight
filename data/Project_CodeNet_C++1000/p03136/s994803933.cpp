#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,temp,m=0,sum=0;
	cin >> n;
	while(n)
	{
		cin >> temp;
		sum += temp;
		m = max(m, temp);
		n--;
	}
	sum -= m;
	m<sum ? cout << "Yes" : cout << "No";
	return 0;
} 