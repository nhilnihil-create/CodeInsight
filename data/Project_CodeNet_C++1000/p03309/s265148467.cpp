#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long ans=0,a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		a[i] -= i;
	} 
	sort(a,a+n);
	for(int i=0;i<n;i++)
		ans += abs(a[n/2]-a[i]);
	cout << ans << endl;
	return 0;
}
