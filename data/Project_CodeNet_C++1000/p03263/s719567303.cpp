//Bismillahir Rahmanir Rahim 
#include<bits/stdc++.h>

using namespace std;

#define ll long long 
#define gcd(a,b) __gcd(a,b)
#define endl '\n'
const int N=2e5+10;
const int inf=1e9;
const int mod=1e9+7;

int  main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

	int h, w;
	cin >> h >> w;

	int a[h+1][w+1];

	vector<pair<pair<int,int>,pair<int,int>>>ans;

	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
			cin >> a[i][j];
	}

	for(int i=1; i<=h; i++)
	{
		for(int j=1; j<w; j++)
		{
			if(a[i][j] & 1)
			{
				a[i][j]--;
				a[i][j+1]++;
				ans.push_back({{i, j}, {i, j+1}});
			}
		}
	}

	for(int i=1; i<h; i++)
	{
		for(int j=1; j<=w; j++)
		{
			if(a[i][j] & 1)
			{
				a[i][j]--;
				a[i+1][j]++;
				ans.push_back({{i, j}, {i+1, j}});
			}
		}
	}

	/*for(int i=1; i<=h; i++)
	{
		for(int j=1; j<=w; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}*/

	cout << ans.size() << endl;

	for(auto it: ans)
		cout << it.first.first << " " << it.first.second << ' ' << it.second.first << " " << it.second.second << endl;
	
	return 0;
}