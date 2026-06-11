#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 55;
ll X[MAX_N],Y[MAX_N];

int main()
{
	int N,K;
	cin >> N >> K;
	rep(i,N)
	{
		cin >> X[i] >> Y[i];
	}
	ll ans = ll(1e19);
	rep(i,N)
	{
		for(int j = i+1; j < N; ++j)
		{
			rep(k,N)
			{
				for(int l = k+1; l < N; ++l)
				{
					ll x1 = X[i], x2 = X[j], y1 = Y[k], y2 = Y[l];
					if (x1 > x2) swap(x1,x2);
					if (y1 > y2) swap(y1,y2);
					int cnt = 0;
					rep(m,N)
					{
						if (x1 <= X[m] && X[m] <= x2 && y1 <= Y[m] && Y[m] <= y2) cnt++;
					}
					if (cnt >= K)
					{
						ans = min(ans,(x2 - x1) * (y2 - y1));
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}