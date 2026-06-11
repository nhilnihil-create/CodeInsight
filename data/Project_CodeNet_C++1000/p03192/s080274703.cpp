#include<bits/stdc++.h>
using namespace std;
int n;
void count2(int n)
{
	int cnt = 0;
	while(n)
	{
		int x = n % 10;
		if(x == 2) cnt++;
		n /= 10;
	}
	cout << cnt << endl;
}
int main()
{
	cin >> n;
	count2(n);
	return 0;
}
