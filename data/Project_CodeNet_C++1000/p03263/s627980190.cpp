#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_HW = 505;
int a[MAX_HW][MAX_HW];
int ans1[MAX_HW*MAX_HW],ans2[MAX_HW*MAX_HW],ans3[MAX_HW*MAX_HW],ans4[MAX_HW*MAX_HW];

int main()
{
	int H,W;
	cin >> H >> W;
	rep(i,H)
	{
		rep(j,W)
		{
			cin >> a[i][j];
		}
	}

	int idx = 0;
	rep(i,H)
	{
		rep(j,W-1)
		{
			if (a[i][j] % 2 == 1)
			{
				a[i][j]--;
				a[i][j+1]++;
				ans1[idx] = i+1;
				ans2[idx] = j+1;
				ans3[idx] = i+1;
				ans4[idx] = j+2;
				idx++;
			}
		}
		if (i < H-1 && a[i][W-1] % 2 == 1)
		{
			a[i][W-1]--;
			a[i+1][W-1]++;
			ans1[idx] = i+1;
			ans2[idx] = W;
			ans3[idx] = i+2;
			ans4[idx] = W;
			idx++;
		}
	}
	cout << idx << endl;
	rep(i,idx)
	{
		cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << " " << ans4[i] << endl;
	}
	return 0;
}