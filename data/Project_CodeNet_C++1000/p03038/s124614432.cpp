#include <bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;

bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b) { 
       return (a.first > b.first); 
}
   	
int main() {
	long long int n, m, sum = 0, count;

	cin >> n >> m;

	long long int a[n], b[m], c[m];
	vector<pair<long long int, long long int>> v;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a+n);

	for (int i = 0; i < m; i++)
	{
		cin >> b[i] >> c[i];
		v.push_back( make_pair(c[i],b[i]) );
	}

	sort(v.begin(), v.end(), sortinrev);
	long long int it = 0;
	for (int i = 0; i < m; i++)
	{
		count = 0;
		while (a[it] <= v[i].first && count < v[i].second)
		{
			a[it] = v[i].first;
			count++;
			it++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}

	cout << sum;

	return 0;
}

