#include<bits/stdc++.h>
#define N 10000000
#define M 17
using namespace std;
typedef long long LL;
LL ten[M+1];
vector<LL> a;
long double S(LL n)
{
	int ans = 0;
	while(n>0)
	{
		ans += n%10;
		n /= 10;
	}
	return ans;
}
long double f(LL x)
{
	return x/S(x);
}
vector<LL> snukes;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ten[0] = 1;
	for(int n = 1; n <= M; n++)
		ten[n] = ten[n-1]*10LL;

	for(int nine_count = 0; nine_count <= M; nine_count++)
		for(LL x = 0; x < ten[min(4,18-nine_count)]; x++)
			if(x%10!=9)
				a.push_back(x*ten[nine_count]+ten[nine_count]-1LL);
	sort(a.begin(),a.end());

	long double best = 1e18;
	for(int i = a.size()-1; i >=0; i--)
		if(f(a[i]) <= best)
		{
			//cout<<f(a[i])<<endl;
			snukes.push_back(a[i]);
			best = f(a[i]);
		}

	reverse(snukes.begin(),snukes.end());

	int k; cin >> k;
	for(int i = 0; i < k; i++)
		cout<<snukes[i]<<endl;

	return 0;
}
