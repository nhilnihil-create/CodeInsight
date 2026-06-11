#include <bits/stdc++.h>
using namespace std;

vector<int> union_find_parent;
int union_find_init(int n);
int union_find_unite(int a,int b);
int union_find_root(int a);

int main()
{
	int n,m;
	cin >> n >> m;

	vector<int> a(m),b(m);
	for (int i=0;i<m;++i)
	{
		cin >> a[i] >> b[i];
	}

	int count=0;
	for (int i=0;i<m;++i)
	{
		union_find_init(n+1);
		for (int j=0;j<m;++j)
		{
			if (i==j)
			{
				continue;
			}
			union_find_unite(a[j],b[j]);
		}
		int root=union_find_root(1);
		for (int j=2;j<=n;++j)
		{
			if (root!=union_find_root(j))
			{
				++count;
				break;
			}
		}
	}
	cout << count << endl;
}

int union_find_init(int n)
{
	union_find_parent.clear();
	for (int i=0;i<n;++i)
	{
		union_find_parent.push_back(i);
	}
	return 0;
}

int union_find_unite(int a,int b)
{
	a=union_find_root(a);
	b=union_find_root(b);
	if (a!=b)
	{
		union_find_parent[a]=b;
	}
	return 0;
}

int union_find_root(int a)
{
	if (union_find_parent[a]==a)
	{
		return a;
	}
	else
	{
		return union_find_parent[a]=union_find_root(union_find_parent[a]);
	}
}







