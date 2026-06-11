#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N;
	cin >> N;
	int ans = 10000;
	rep(i,N)
	{
		ll A;
		cin >> A;
		int temp = 0;
		while(A % 2 == 0)
		{
			A /= 2;
			temp++;
		}
		ans = min(ans,temp);
	}
	cout << ans << endl;
	return 0;
}