#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,h,w,a,b;
	int res = 0;

	cin >> n >> h >> w;

	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		if(a>=h && b>=w)
		{
			res++;
		}
	}

	cout << res << '\n';

	return 0;
}