#include<bits/stdc++.h>
using namespace std;
void c_p_c()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int main()
{
	//c_p_c();
	int n, k;
	cin >> n >> k;
	int count = 1;
	while (n--)
	{
		int temp = count * 2;
		int temp1 = count + k;
		if (temp > temp1)
			count = temp1;
		else
			count = temp;
	}
	cout << count << endl;
}