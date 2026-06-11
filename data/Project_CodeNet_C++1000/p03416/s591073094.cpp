#include<bits/stdc++.h>
using namespace std;
int main()
{  ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	for(int i = a; i <= b; i++)
	{
		int  digit;
		int p = i ;
		int k = i;
		int rev = 0;

		do
		{
			digit = k % 10;
			rev = (rev * 10) + digit;
			k = k/ 10;

		} while(k != 0);
		if(p == rev)
		{
			cnt ++;
		}
		else
			continue ;
	}
	cout << cnt << "\n";
	return 0;
}