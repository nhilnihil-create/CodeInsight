#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 10000000;
	for(int i =0;i<=n;i++)
	{
		int c=0,t=i;
		while(t>0)
		{
			c+=t%6;
			t/=6;
		}
		t = n - i;
		while(t>0)
		{
			c+=t%9;
			t/=9;
		}
		if(ans>c)
		{
			ans = c;
		}
	}
    cout << ans << endl;
	return 0;
}
