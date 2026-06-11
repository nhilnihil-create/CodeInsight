#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n,k,ans=1;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
		{
			
			ans = min(ans*2,ans+k);
		}
		cout<<ans;	

   return 0;
}
