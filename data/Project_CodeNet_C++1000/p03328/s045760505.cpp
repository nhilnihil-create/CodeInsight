#include<bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout << #x << " = "<< x << "\n";

signed main()
{
	//freopen("in,txt", "r",stdin);
	//freopen("out.txt" ,"w", stdout);
	
	int a, b; cin >> a >> b;
	
	for(int i = 1, j = 2; i <= 998; i++, j++)
	{
		int x = i * (i+1)/2;
		int y = j * (j+1)/2;
		if(a - x == b - y)
		{
			cout << abs(a - x) << "\n";
			return 0;
		}
	}
	
	
}