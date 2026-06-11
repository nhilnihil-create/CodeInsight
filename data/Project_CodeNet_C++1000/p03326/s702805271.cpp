#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 1005;
ll x[MAX_N],y[MAX_N],z[MAX_N],w[MAX_N];

ll f(int a)
{
	if (a == 0) return ll(1);
	else return ll(-1);
}

int main()
{
	int N,M;
	cin >> N >> M;
	rep(i,N)
	{
		cin >> x[i] >> y[i] >> z[i];
	}
	ll ans = 0 ,temp = 0;
	int a,b,c;
	for (int i = 0; i < 8; ++i)
	{
		temp = 0;
		a = i & (1 << 0), b = i & (1 << 1), c = i & (1 << 2);
		rep(j,N)
		{
			w[j] = x[j]*f(a) + y[j]*f(b) + z[j]*f(c);
		}
		sort(w,w+N);
		/*
		rep(j,N)
		{
			cout << w[j] << " ";
		}
		cout << endl;
		*/
		rep(j,M)
		{
			temp += w[N-1-j];
		}
		ans = max(ans,temp);
	}
	cout << ans << endl;
	return 0;
}