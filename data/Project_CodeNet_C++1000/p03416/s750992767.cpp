#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int A,B;
	cin >> A >> B;
	int ans = 0;
	for (int i = A; i <= B; ++i)
	{
		bool flag = true;
		if (i / 10000 != i % 10) flag = false;
		if ((i / 1000) % 10 != (i % 100) / 10) flag = false;
		if (flag) ans++;
	}
	cout << ans << endl;
	return 0;
}