#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
ll A[MAX_N],B[MAX_N];
map<ll,ll> C;

int main()
{
	int N;
	ll M;
	cin >> N >> M;
	rep(i,N)
	{
		cin >> A[i];	
		A[i] %= M;
	}

	B[0] = 0;
	rep(i,N)
	{
		B[i+1] = (B[i] + A[i]) % M;
	}
	ll ans = 0;
	C[B[0]]++;
	rep(i,N)
	{
		ans += C[B[i+1]];
		C[B[i+1]]++;
	}
	cout << ans << endl;
	return 0;
}