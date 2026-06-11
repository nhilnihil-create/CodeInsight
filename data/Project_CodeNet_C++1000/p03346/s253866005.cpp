#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
//typedef pair<int,int> P;
const int MAX_N = 200005;
int P[MAX_N],Q[MAX_N];

int main()
{
	int N;
	cin >> N;
	rep(i,N)
	{
		cin >> P[i];
		Q[P[i]-1] = i;
	}
	int cnt = 1, temp = Q[0], res = 1;
	rep(i,N-1)
	{
		if (temp < Q[i+1])
		{
			cnt++;
			res = max(res,cnt);
		}
		else
		{
			cnt = 1;
		}
		temp = Q[i+1];
		//cout << cnt << " " << res << endl;
	}
	cout << N-res << endl;
	return 0;
}