#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	ll N,M;
	cin >> N >> M;
	if (N == 1 && M == 1) cout << 1 << endl;
	else if(N == 1 || M == 1) cout << max(N,M)-2 << endl;
	else cout << (N-2) * (M-2) << endl;
	return 0;
}