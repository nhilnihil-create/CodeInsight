#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int mxn = 200010;
ll dp[mxn], a[mxn], h[mxn], t[2*mxn];
int N;

void update(int idx, ll val)
{
	idx--; idx+=N; t[idx] = val; idx/=2;
	while(idx) t[idx] = max(t[2*idx], t[2*idx+1]), idx/=2;
}

ll query(int l, int r)
{
	l--, r--; l+=N, r+=N;
	ll ret = 0ll;
	for(; l<=r; l/=2, r/=2)
	{
		if(l&1) ret = max(ret, t[l]);
		if(!(r&1)) ret = max(ret, t[r]);
		l++, r--;
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N;
	for(int i=1; i<=N; i++) cin>>h[i];
	for(int i=1; i<=N; i++) cin>>a[i];

	dp[1] = a[1];
	update(h[1], dp[1]);
	for(int i=2; i<=N; i++)
		dp[i] = query(1, h[i]-1)+a[i], update(h[i], dp[i]);

	ll ret = query(1, N);
	cout << ret << '\n';

	return 0;
}