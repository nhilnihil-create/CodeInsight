#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 300005;
int cntE[MAX_N],cntW[MAX_N];

int main()
{
	int N;
	cin >> N;
	string S;
	cin >> S;
	int ans = N;
	rep(i,N)
	{
		if (S[i] == 'W') cntW[i+1]++;
		else cntE[i+1]++;
	}
	rep(i,N)
	{
		cntW[i+1] += cntW[i];
		cntE[i+1] += cntE[i];
	}
	rep(i,N)
	{
		ans = min(ans,cntW[i]+cntE[N]-cntE[i+1]);
	}
	cout << ans << endl;
	return 0;
}