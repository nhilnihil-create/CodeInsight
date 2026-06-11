#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i<n;i++)cin >> a[i];
	sort(a.begin(),a.end());
	a.back() /=2;
	int ans = 0;
	for(int i = 0;i<n;i++)ans+=a[i];

	cout << ans << endl;
}
