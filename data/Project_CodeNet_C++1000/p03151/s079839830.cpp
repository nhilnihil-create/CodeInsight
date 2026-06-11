#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100000000;

int main()
{
	int n;
	cin >> n;
	vector<ll> A(n),B(n),Z(n);
	rep(i,n)cin >> A[i];
	rep(i,n)cin >> B[i];

	rep(i,n)Z[i]=A[i]-B[i];
	sort(ALL(Z));
	//rep(i,n)cout<<Z[i]<<ndl;
	int left=0,right=n-1;
	ll now = 0;
	int ans = 0;
	while(Z[left]<0)
	{
		if(now+Z[left]<0)
		{
			now += Z[right--];
			ans ++;
		}
		now +=Z[left++];
		ans ++;
	}
	if(now<0)
	cout<<-1<<endl;
	else
	cout<<ans<<endl;
	return 0;
}