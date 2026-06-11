#include <bits/stdc++.h>

using namespace std;

map <int,int> d;

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n,m,t;

	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		cin >> t;
		d[t] += 1;
	}
	cin >> m;
	for(int i=0;i<m;i++)
	{
		cin >> t;
		d[t] -= 1;
		if(d[t] < 0)
		{
			cout << "NO" << '\n';
			return 0;
		}
	}

	cout << "YES" << '\n';
	return 0;
}