#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int MAX_NM = 100005;
ll A[MAX_NM],B[MAX_NM],C[MAX_NM];
vector<P> v;

int main()
{
	int N,M;
	cin >> N >> M;
	rep(i,N)
	{
		cin >> A[i];
	}
	rep(i,M)
	{
		cin >> B[i] >> C[i];
		v.push_back(P(C[i],B[i]));
	}
	sort(A,A+N);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ll ans = 0;
	int idx = 0;
	rep(i,N)
	{
		if (v[idx].first > A[i] && v[idx].second > 0)
		{
			ans += v[idx].first;
			v[idx].second--;
			if (v[idx].second == 0 && idx < v.size()-1) idx++;
		}
		else
		{
			ans += A[i];
		}
	}
	cout << ans << endl;
	return 0;
}