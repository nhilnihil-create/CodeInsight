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

ll A,B,C,D;

ll GCD(ll A,ll B){
    if(B == 0) return A;
    else return GCD(B,A%B);
}

bool solve(){
    if(A < B) return 0;
    if(D < B) return 0;
    if(C >= B - 1) return 1;
    ll G = GCD(B,D);
    ll maxv = (C - A%G + G)/G;
    if(A%G + G*maxv < B) return 0;
    else return 1;
}

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    int T;cin >> T;
    bool flag = 0;
    REP(query,T){
        flag = 0;
        cin >> A >> B >> C >> D;
        if(!solve()) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}