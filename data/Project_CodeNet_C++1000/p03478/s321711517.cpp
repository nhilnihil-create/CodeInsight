#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N,A,B;
	cin >> N >> A >> B;
	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		int temp = i;
		int now = 0;
		while(temp > 0)
		{
			now += temp % 10;
			temp /= 10;
		}
		if (now >= A && now <= B)
		{
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}