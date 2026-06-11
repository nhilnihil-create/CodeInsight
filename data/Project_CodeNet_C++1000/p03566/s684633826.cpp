#include <bits/stdc++.h>
#include <complex>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,C,L,R;
string S,T;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;


int main() {
    cin>>N;
    vec t(N+1), v(N+1);
    rep(i,N){
        cin>>t[i];
        t[i] <<= 1;
        if(i != 0) t[i] += t[i-1];
    }
    rep(i,N) {
        cin>>v[i];
        v[i] <<= 1;
    }
    t[N] = t[N-1] + 1;
    v[N] = 0;
    ll take_care = N + 1;
    ll lastv = 0;
    vec run(t[N],0);
    reps(i,1,t[N]){
        ++lastv;
        for(int j = N; j > N + 1 - take_care; --j){
            lastv = min(lastv, v[j] + t[j-1] - i);
        }
        lastv = min(lastv, v[N + 1 - take_care]);
        run[i] = lastv;
        if(i == t[N + 1 - take_care]) --take_care;
    }
    ll ans = 0;
    reps(i,1,t[N]) ans += run[i];
    long double out = ans;
    out /= 4.0;
    cout<<fixed<<setprecision(11)<<out<<endl;
}