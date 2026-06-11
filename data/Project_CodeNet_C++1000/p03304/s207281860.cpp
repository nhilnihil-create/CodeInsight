#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr int INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
	cout << setprecision(20);
    double N,M,D;cin >> N >> M >> D;
    double ans = 0;
    if(N - D < D + 1 || D == 0){
        cout << (1/N)*(M-1) << endl;
    }
    else{
        ans += (2*D/N)*(1/N);
        ans += ((N-2*D)/N)*(2/N);
        cout << ans*(M-1) << endl;
    }
}