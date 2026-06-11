#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a, b, cnt = 0;
	cin >> a >> b;
	for(long long i=b + 1; i<=a; i++)
	{
		long long temp = i;
		cnt += (a / temp) * max(0ll, temp - b);
		temp = a % temp;
		cnt += max(0ll, temp - b + 1);
	}
	if(b == 0) cnt -= a;
	cout << cnt << '\n';
	return 0;
}