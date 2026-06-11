#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
bool used[105];

int main()
{
	int N;
	cin >> N;
	int ans = 0;
	rep(i,N)
	{
		int d;
		cin >> d;
		if (!used[d])
		{
			ans++;
			used[d] = true;
		}
	}
	cout << ans << endl;
	return 0;
}