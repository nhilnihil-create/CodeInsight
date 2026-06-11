#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_C = 35;
const int MAX_N = 505;
int D[MAX_C][MAX_C],c[MAX_N][MAX_N],d0[MAX_C],d1[MAX_C],d2[MAX_C];
int ch0[MAX_C],ch1[MAX_C],ch2[MAX_C];

int main()
{
	int N,C;
	cin >> N >> C;
	rep(i,C)
	{
		rep(j,C)
		{
			cin >> D[i+1][j+1];
		}
	}
	rep(i,N)
	{
		rep(j,N)
		{
			cin >> c[i][j];
			if ((i+j) % 3 == 0) d0[c[i][j]]++;
			if ((i+j) % 3 == 1) d1[c[i][j]]++;
			if ((i+j) % 3 == 2) d2[c[i][j]]++;
		}
	}

	rep(i,C)
	{
		rep(j,C)
		{
			ch0[i+1] += D[j+1][i+1] * d0[j+1];
			ch1[i+1] += D[j+1][i+1] * d1[j+1];
			ch2[i+1] += D[j+1][i+1] * d2[j+1];
		}
	}

	int ans = 1000 * 500 * 500 + 10;
	rep(i,C)
	{
		rep(j,C)
		{
			rep(k,C)
			{
				if (i != j && j != k && k != i)
				{
					//cout << i << " " << j << " " << k << "  " << ch0[i+1]+ch1[j+1]+ch2[k+1] << endl;
					ans = min(ans,ch0[i+1]+ch1[j+1]+ch2[k+1]);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}