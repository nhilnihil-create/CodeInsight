#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int Par[200001],Size[200001];
int Pos[200001];


void init(int n)
{
	for(int i = 0;i<=n;i++)
	{
		Par[i] = i;
		Size[i] = 1;
	}
}


int main()
{
	int n;
	cin >> n;
	init(n);
	vector<int> a(n);
	for(int i = 0;i<n;++i)
	{
		cin >> a[i];
		Pos[a[i]] = i+1;
	}

	for(int i = 0;i<n;i++)
	{
		if(Par[a[i]]!=a[i])continue;
		int now = a[i];
		//cout<<';'<<endl;
		while(1)
		{
			if(Pos[now]<Pos[now+1])
			{
				Size[a[i]]++;
				Par[now+1] = 30000000;
				now++;
			}
			else break;
		}
	}
	ll ans = 0;
	for(int i = 0;i<=n;i++)ans = max<ll>(Size[i],ans);
	cout<<n-ans<<endl;

}