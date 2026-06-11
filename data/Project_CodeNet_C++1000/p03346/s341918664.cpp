#include <bits/stdc++.h>

using namespace std;

int arr[200001];
int idx[200001];
set <int,greater<int>> s;
int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,t;
	vector <int> v;

	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		v.push_back(t);
	}

	int num = 0;
	int Max = 0;
	for(int i=0;i<n;i++)
	{
		auto it = s.upper_bound(v[i]);
		if(it==s.end() || *it!=v[i]-1)
		{
			idx[v[i]] = num;
			arr[num++]+=1;
			s.insert(v[i]);
		}
		else
		{
			//cout << *it << ' ' << v[i] << '\n';
			int idx2 = idx[*it];
			arr[idx2]+=1;
			idx[v[i]] = idx2;
			s.erase(*it);
			s.insert(v[i]);
		}
	}

	for(int i=0;i<num;i++)
	{
		Max = max(Max,arr[i]);
	}

	cout << n - Max << '\n';

	return 0;
}