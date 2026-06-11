#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<ll> D;

int main()
{
	ll N,M;
	cin >> N >> M;
	for (int i = 1; i*i <= M; ++i)
	{
		if (M % i == 0)
		{
			D.push_back(i);
			D.push_back(M/i);
		}
	}
	sort(D.begin(), D.end());
	ll a = M/N;
	for (int i = D.size()-1; i >= 0; --i)
	{
		if (D[i] <= a)
		{
			cout << D[i] << endl;
			return 0;
		}
	}
	return 0;
}