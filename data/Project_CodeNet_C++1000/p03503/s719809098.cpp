#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<string> s(n);
	int a[n][5][2];
	string t = "";
	char g='\n';
	for(int i = 0; i<n; i++)
	{
		for(int j = 0 ;j<10; j++)
		{
			cin>>g;
			t.push_back(g);
		}
		s[i]=t;
		t = "";
	}
	int p[n][11];
	for(int i = 0; i<n; i++)
		for(int j = 0; j<11; j++)
			cin>>p[i][j];
	ll ans[(1<<11)] = {0};
	ans[0] = -1e15;
	for(int i = 1; i<(1<<11); i++)
	{
		bitset<12> b(i);
		int com = 0;
		for(int k =0; k<n; k++)
		{
			bitset<12> b2(s[k]);
			b2 &= b;
			com += b2.count();
			ans[i] += p[k][b2.count()];
		}
		if(com==0)
			ans[i] = -1e15;
	}
	cout<<*max_element(ans,ans+(1<<11))<<endl;
	return 0;
}