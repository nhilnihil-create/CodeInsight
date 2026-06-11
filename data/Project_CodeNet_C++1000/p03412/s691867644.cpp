#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<long long>a(n),b(n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0; i<n; i++)
		cin>>b[i];
	long long ans = 0;
	for(int i=0; i<30; i++)
	{
		vector<long long>ord_a(n),ord_b(n);
		for(int j=0; j<n; j++)
		{
			ord_a[j]=a[j] % (1 << (i+1));
			ord_b[j]=b[j] % (1 << (i+1));
		}
		sort(ord_b.begin(),ord_b.end());
		long long res=0;
		long long low=1<<i;
		for(auto& v:ord_a)
		{
			res+=lower_bound(ord_b.begin(), ord_b.end(), low*2 - v) - lower_bound(ord_b.begin(), ord_b.end(), low - v);
			res+=lower_bound(ord_b.begin(), ord_b.end(), low*4 - v) - lower_bound(ord_b.begin(), ord_b.end(), low*3 - v);
		}
		ans+=res%2<<i;
	}
	cout<<ans<<"\n";
	return 0;
}
