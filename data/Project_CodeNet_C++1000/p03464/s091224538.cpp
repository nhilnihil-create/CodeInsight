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
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    int N;cin >> N;
    ll A[N];REP(i,N) cin >> A[i];
    ll left = 2,right = 3;
    if(A[N-1] != 2){
        cout << -1 << endl;
        return 0;
    }
    rep(i,N){
        if(i == N-1) continue;
        if(right / A[i] == 0){
            cout << -1 << endl;
            return 0;
        }
        if(left % A[i] != 0) left = (left/A[i]+1)*A[i];
        right = (right/A[i]+1)*A[i]-1;
        if(left > right){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << left << ' ' << right << endl;
}