#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N;
	cin >> N;
	int ans = N;
	for (int i = 0; i <= N; ++i)
	{
		int t = i,cnt = 0;
		while(t > 0)
		{
			cnt += t % 6;
			t /= 6;
		}
		t = N-i;
		while(t > 0)
		{
			cnt += t % 9;
			t /= 9;
		}
		if (cnt <= N)
		{
			ans = min(ans,cnt);
		}
		
	}
	cout << ans << endl;
	return 0;
}