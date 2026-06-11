#include<bits/stdc++.h>

using namespace std;

#define task "cf"
#define ff(i, a, b) for(int i=a; i<=b; ++i)
#define fd(i, a, b) for(int i=a; i>=b; --i)
#define ll long long

const int N = 262149;
int f_max[N], g_max[N];
int k, n, a[N];

void enter()
{
	cin >> k;
	n = 1 << k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
}

int getBit(int x, int i)
{
	return (x >> i ) & 1;
}

void solve()
{
	f_max[0] = 0;
	int cur_best = 0;
	for(int x = 1; x < n; ++x)
	{
		f_max[x] = x;
		g_max[x] = -1;
		int testMax = cur_best;
		vector<int> v;
		while(!v.empty())
			v.pop_back();
		for(int i = 0; i <= 18; ++i)
			if(getBit(x, i) == 1)
			{
				int y = x & ~ (1 << i);
				testMax = max(testMax, a[f_max[y]] + a[x]);
				v.push_back(y);
				if(a[f_max[x]] < a[f_max[y]])
					f_max[x] = f_max[y];
			}
		for(int i = 0; i <= 18; ++i)
			if(getBit(x, i) == 1)
			{
				int y = x & ~ (1 << i);
				if(f_max[x] != f_max[y] && a[g_max[x]] < a[f_max[y]] )
				g_max[x] = f_max[y];
			}
		for(int i = 0; i < v.size(); ++ i)
			for(int j = i + 1; j < v.size(); ++j)
			{
				int pos1 = f_max[v[i]];
				int pos2 = f_max[v[j]];
				if(pos1 != pos2) testMax = max(testMax, a[pos1] + a[pos2]); else
					{
						int subPos1 = g_max[v[i]];
						int subPos2 = g_max[v[j]];
						if(subPos1 != -1) testMax = max(testMax, a[subPos1] + a[pos2]);
						if(subPos2 != -1) testMax = max(testMax, a[pos1] + a[subPos2]);
					}
			}	
		cur_best = max(cur_best, testMax);
		cout << testMax << endl;
	}
	//cout<<endl << " " << f_max[14] << " " << f_max[13] << endl;
}

int main() {
		enter();
		solve();
	return 0;
}