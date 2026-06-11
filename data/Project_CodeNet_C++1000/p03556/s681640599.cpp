#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N;
	cin >> N;
	int ans = 1;
	int i = 1;
	while (i*i <= N)
	{
		ans = i*i;
		i++;
	}
	cout << ans << endl;
	return 0;
}