#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<ll> sum(N+1);
    rep(i,N) sum[i+1] = sum[i] + A[i];
    ll ans = LINF;
    repr(i,2,N-1){
        ll k = sum[i]/2;
        int d = lower_bound(sum.begin(),sum.end(),k)-sum.begin();
        ll k2 = (sum[N]+sum[i])/2;
        int d2 = lower_bound(sum.begin(),sum.end(),k2)-sum.begin();
        ll P = -1,Q = -1,R = -1,S = -1;
        rep(j,2)rep(r,2){
            int a = d-j;
            if(a >= 1 && a < i){
                P = sum[a];
                Q = sum[i]-sum[a];
            }
            int b = d2-r;
            if(b > i && b < N){
                R = sum[b]-sum[i];
                S = sum[N]-sum[b];
            }
            //cout << P << " " << Q << " " << R << " " << S << endl;
            if(P == -1 || Q == -1 || R == -1 || S == -1) continue;
            ans = min(ans,max({P,Q,R,S})-min({P,Q,R,S}));
        }
    }
    cout << ans << endl;
}
