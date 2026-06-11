#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int pow6[10],pow9[10];

void init()
{
	pow6[0] = 1;
	pow9[0] = 1;
	rep(i,9)
	{
		pow6[i+1] = pow6[i] * 6;
		pow9[i+1] = pow9[i] * 9;
	}
}

int main()
{
	init();
	int N;
	cin >> N;
	int ans = N;
	for (int i = 0; i*6 < 100005; ++i)
	{
		for (int j = 0; j*9 < 100005-i*6; ++j)
		{
			int temp = i*6+j*9, cnt = 0;
			int t = i;
			while(t > 0)
			{
				cnt += t % 6;
				t /= 6;
			}
			t = j;
			while(t > 0)
			{
				cnt += t % 9;
				t /= 9;
			}
			if (temp <= N)
			{
				ans = min(ans,cnt+N-temp);
				//cout << i << " " << j << " " << cnt << " " << temp << " " << cnt+N-temp << endl;
			}
		}
		
	}
	cout << ans << endl;
	return 0;
}