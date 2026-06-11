#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i = 0;i<n;i++)
		cin >> b[i];

	int Ans = 0;

	for(int i = 0;i<n;i++)
	{
		int ans = 0;
		for(int j = 0;j<=i;j++)ans+=a[j];
		for(int j = i;j<n;j++)ans+=b[j];
		Ans = max(ans,Ans);
	}
	cout<<Ans<<endl;
	return 0;
}
