#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, H, W; cin >> N >> H >> W;
	int res = (N - H + 1)*(N - W + 1);

	cout << res << endl;

	return 0;
}