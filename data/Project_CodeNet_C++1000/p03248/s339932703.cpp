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
    string S;cin >> S;
    int N = S.size();
    int p = 1;
    REPP(i,0,N-1){
        if(S[i] == S[N-2-i]) continue;
        cout << -1 << endl;
        return 0;
    }
    if(S[0] == '0' || S[N-1] == '1'){
        cout << -1 << endl;
        return 0;
    }
    REPP(i,2,N+1){
        if(S[i-1] == '1') for(;p < i;++p)cout << i << ' ' << p << endl;
    }
	cout << N << ' ' << N-1 << endl;
}