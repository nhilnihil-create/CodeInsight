#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> Treeleft, Treeright;
vector <int> Treecnt;
void update1(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		Treeright[v] = min(Treeright[v], val);
	}
	else if(l <= ar && r >= al)
	{
		update1(v * 2, l, (r + l) / 2, al, ar, val);
		update1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
void update2(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar){
		Treeleft[v] = max(Treeleft[v], val);
	}
	else if(l <= ar && r >= al)
	{
		update2(v * 2, l, (r + l) / 2, al, ar, val);
		update2(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
	}
}
int ans1(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return Treeleft[v];
	}
	else if(ind <= (r + l) / 2)
	{
		return max(Treeleft[v], ans1(v * 2, l, (r + l) / 2, ind)); 
	}
	else
	{
		return max(Treeleft[v], ans1(v * 2 + 1, (r + l) / 2 + 1, r, ind));
	}
}
int ans2(int v, int l, int r, int ind)
{
	if(l == r)
	{
		return Treeright[v];
	}
	else if(ind <= (r + l) / 2)
	{
		return min(Treeright[v], ans2(v * 2, l, (r + l) / 2, ind));
	}
	else
	{
		return min(Treeright[v], ans2(v * 2 + 1, (r + l) / 2 + 1, r, ind));
	}
}
void update3(int v, int l, int r, int ind)
{
	if(l == r)
	{
		Treecnt[v]++;
	}
	else if(ind <= (r+ l) / 2)
	{
		update3(v * 2, l, (r + l) / 2, ind);
		Treecnt[v]++;
	}
	else
	{
		update3(v * 2 + 1, (r + l) / 2 + 1, r, ind);
		Treecnt[v]++;
	}
}
int ans3(int v, int l, int r, int al, int ar)
{
	if(al <= l && r <= ar)
	{
		return Treecnt[v];
	}
	else if(al <= r && ar >= l)
	{
		return ans3(v * 2, l, (r + l) / 2, al, ar) + ans3(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	else
	{
		return 0;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, q;
	cin >> n >> k >> q;
	Treecnt.resize(4 * n);
	Treeleft.resize(4 * n);
	Treeright.resize(4 * n);
	vector <int> A(n);
	vector <pair <int, int> > B(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		B[i] = {A[i], i};
	}
	sort(B.begin(), B.end());
	int ans = 1e9;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 4 * n; j++)
		{
			Treeright[j] = n;
			Treeleft[j] = -1;
			Treecnt[j] = 0;
		}
		for(int j = 0; j < i; j++)
		{
			update1(1, 0, n - 1, 0, B[j].second, B[j].second);
			update2(1, 0, n - 1, B[j].second, n - 1, B[j].second);
		}
		int cnt = 0;
	//	cout << i << "\n";
		int p1 = 1e9;
		for(int j = i; j < n; j++)
		{
			int l1 = ans1(1, 0, n - 1, B[j].second);
			int r1 = ans2(1, 0, n - 1, B[j].second);
			if(l1 + 1 <= r1)
			{
				int e = ans3(1, 0, n - 1, l1 + 1, r1 - 1);
	//			cout << j << " " << l1 << " " << r1 << " " << e << "\n";
				if(r1 - l1 - 1 - e>= k)
				{
	//				cout << j << "\n";
					cnt++;
					p1 = min(p1, B[j].first);
					update3(1, 0, n - 1, B[j].second);
				}
			}
			if(cnt >= q)
			{
				ans = min(ans, B[j].first - p1);
				break;
			}
		}
	}
	cout << ans;
    return 0;
}