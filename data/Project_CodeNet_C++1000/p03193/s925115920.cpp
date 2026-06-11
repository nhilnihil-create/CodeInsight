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
	int res = 0;
	rep (i, N){
		int A, B; cin >> A >> B;
		res += (int)(A >= H && B >= W);
	} // end rep
	cout << res << endl;

	return 0;
}