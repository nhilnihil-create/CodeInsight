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
    int N;cin >> N;
    vector<int> D(N);
    REP(i,N) cin >> D[i];
  	sort ALL(D);
    //sort(D.begin(), D.end()); D.erase(unique(D.begin(), D.end()), D.end());
    N = D.size();
    vector<int> M(N),V(N);
  	M = D;V = D;
    REP(i,M.size()){
        if(i % 2 == 0) M[i] = (24 - M[i]);
        else V[i] = (24 - V[i]);
    }
  	V.pb(0);V.pb(24);M.pb(0);M.pb(24);
    sort ALL(M);sort ALL(V);
    int minv = INF,minm = INF;
    REP(i,M.size()-1){
        minv = min(minv,M[i+1] - M[i]);
        minm = min(minm,V[i+1] - V[i]);
    }
    cout << max(minv,minm) << endl;
}