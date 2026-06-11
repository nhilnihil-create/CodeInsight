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
constexpr ll INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll minv = min(X,Y),ans = 0;;
    if(A+B >= 2*C){
        ans += 2*C*minv;
    }else{
        ans += (A+B)*minv;
    }
    X -= minv;
    Y -= minv;
    if(A >= 2*C){
        ans += 2*C*X;
    }else{
        ans += A*X;
    }

    if(B >= 2*C){
        ans += 2*C*Y;
    }else{
        ans += B*Y;
    }

    cout << ans << endl;
}