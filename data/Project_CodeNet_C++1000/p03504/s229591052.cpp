#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
const int MAX_C = 35;
int s[MAX_N],t[MAX_N],c[MAX_N],sums[MAX_N],sumt[MAX_N];
bool cs[MAX_C][MAX_N],ct[MAX_C][MAX_N];

int main()
{
	int N,C;
	cin >> N >> C;
	rep(i,N)
	{
		int p;
		cin >> s[i] >> t[i] >> p;
		c[i] = p-1;
		sums[s[i]]++; sumt[t[i]]++;
		cs[c[i]][s[i]]++; ct[c[i]][t[i]]++;
	}
	rep(i,C)
	{
		rep(j,MAX_N)
		{
			if (cs[i][j] && ct[i][j])
			{
				sums[j]--; sumt[j]--;
			}
		}
	}
	rep(i,MAX_N-1)
	{
		sums[i+1] += sums[i];
		sumt[i+1] += sumt[i];
	}
	/*
	rep(i,15)
	{
		cout << sums[i] << " ";
	}
	cout << endl;
	rep(i,15)
	{
		cout << sumt[i] << " ";
	}
	cout << endl;
	*/
	int ans = 0;
	rep(i,MAX_N-1)
	{
		ans = max(ans,sums[i+1] - sumt[i]);
	}
	cout << ans << endl;
	return 0;
}