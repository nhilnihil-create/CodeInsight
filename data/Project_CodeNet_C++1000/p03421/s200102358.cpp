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
const ll MOD = 998244353;
const ll INF = 1LL << 61;
const long double EPS = 1e-9;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main(){
    cin>>N>>A>>B;
    if(A*B < N || A+B > N+1){
        cout<<-1<<endl;
        return 0;
    }
    vec ans(N);
    rep(i,N) ans[i] = N - i;
    //reverse(ans.begin(), ans.begin() + 2);
    for(ll i = N; i >= 0; i -= A){
        ll left = max({0LL, i - A, --B});
        reverse(ans.begin() + left, ans.begin() + i);
    }
    rep(i,N) cout<<ans[i]<<(i == N - 1 ? '\n' : ' ');
    return 0;
}