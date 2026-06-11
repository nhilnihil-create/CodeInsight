#include <bits/stdc++.h>
using namespace std;

void code();

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    code();
}

void code()
{
	int a, b;
	cin >> a >> b;
	int cnt =0;
	for (int i = a; i <= b; ++i)
	{
		int rem, temp = i;
		int reverse = 0;
		while(temp){
			rem = temp%10;
			temp *= 0.1;
			reverse = reverse*10+rem;
		}
		if(reverse == i)
			cnt++;
	}
	cout << cnt << endl;
}