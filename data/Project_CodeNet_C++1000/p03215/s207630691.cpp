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

ll N,K,cnt = 0,ans = 0LL;

void solve(vector<ll> &V){
    bool flag = 0;
    repp(i,40,0){
        vector<ll> W;
        ll bit = (1LL << (i)); 
        ll Y = 0;
        REP(j,V.size()){
            if((bit & V[j]) == bit){
                ll D = V[j] & ~(1LL<<(i));
                W.pb(D);
                ++Y;
            }
        }
        if(Y >= K){
            ans += bit;
            V.swap(W);
        }
    }
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
    cin >> N >> K;
    vector<ll> A(N),V;
    REP(i,N){cin >> A[i];}
    REP(i,N){
        ll sum = 0;
        REPP(j,i,N){
            sum += A[j];
            V.pb(sum);
        }
    }
    sort ALL(V);
    reverse ALL(V);
    solve(V);
    cout << ans << endl;
}
