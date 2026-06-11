#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

ll dp[100][2];
int main()
{
	int N;
	cin >> N;
	ll K;
	cin >> K;
	vector<ll> A(N);
	rep(i, N)cin>>A[i];

	for (int i = 0; i < 100; i++) dp[i][0] = dp[i][1] = -1;
	dp[45][0] = 0;
	for(int d = 44; d >= 0; --d){
		ll mask = 1LL<<d;
		int num = 0;
		for (int i = 0; i < N; i++) if(A[i] & mask) ++num; // d桁目が立ってるやつの数

		if (dp[d+1][1] >= 0) chmax(dp[d][1], dp[d+1][1] + mask * max(num, N-num));
		if (dp[d+1][0] >= 0) {
			if (K & (1LL<<d)) {
				chmax(dp[d][1], dp[d+1][0] + mask * num);
				chmax(dp[d][0], dp[d+1][0] + mask * (N - num));
			}
			else {
				chmax(dp[d][0], dp[d+1][0] + mask * num);
			}
		}
	}
	cout << max(dp[0][0], dp[0][1]) << endl;
}
