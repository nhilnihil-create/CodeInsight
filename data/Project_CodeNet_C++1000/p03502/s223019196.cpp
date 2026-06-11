#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N;
	cin >> N;
	int temp = N, cnt = 0;
	while (temp > 0)
	{
		cnt += temp % 10;
		temp /= 10;
	}
	if (N % cnt == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}