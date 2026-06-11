#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_XYZ = 1005;
ll A[MAX_XYZ],B[MAX_XYZ],C[MAX_XYZ],ans[MAX_XYZ*3];
ll X,Y,Z,K;

bool f(ll x)
{
	ll cnt = 0;
	rep(i,X)
	{
		rep(j,Y)
		{
			ll s = A[i]+B[j];
			int l = -1, r = Z;
			while(l+1 < r)
			{
				int m = (l+r)/2;
				if (s+C[m] >= x) l = m;
				else r = m;
			}
			cnt += l+1;
		}
	}
	if (cnt >= K) return true;
	else return false;
}

int main()
{
	cin >> X >> Y >> Z >> K;
	rep(i,X)
	{
		cin >> A[i];
	}
	sort(A,A+X);
	reverse(A,A+X);
	rep(i,Y)
	{
		cin >> B[i];
	}
	sort(B,B+Y);
	reverse(B,B+Y);
	rep(i,Z)
	{
		cin >> C[i];
	}
	sort(C,C+Z);
	reverse(C,C+Z);
	ll l = 0, r = ll(1e11);
	while(l+1 < r)
	{
		ll m = (l+r)/2;
		if (f(m)) l = m;
		else r = m;
		//cout << l << " " << r << endl;
	}
	ll cnt = 0;
	bool flag;
	rep(i,X)
	{
		rep(j,Y)
		{
			flag = false;
			rep(k,Z)
			{
				if (A[i]+B[j]+C[k] > l)
				{
					ans[cnt] = A[i]+B[j]+C[k];
					cnt++;
				}
				else break;
			}
		}
	}
	while(cnt < K)
	{
		ans[cnt] = l;
		cnt++;
	}
	sort(ans,ans+cnt);
	reverse(ans,ans+cnt);
	rep(i,cnt)
	{
		cout << ans[i] << endl;
	}
	return 0;
}