#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

ll extgcd(ll a, ll b, ll &x, ll &y){
    ll d = a;
    if(b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    }else{
        x=1;
        y=0;
    }
    return d;
}

int main() {
    ll C, D;
    cin>>N;
    rep(i,N) {
        ll x, y;
        cin >> A >> B >> C >> D;
        if(B > D || B > A) {
            S = "No";
        }else if(C + 1 >= B) {
            S = "Yes";
        }else {
            ll g = extgcd(max(B, D), min(B, D), x, y);
            K = (max(0LL, C - (A % B) + g)) / g;
            S = K * g + (A%B) < B ? "No" : "Yes";
            //if(K * g + (A%B) <= C) cout<<i<<' '<<K<<endl;
        }
        cout<<S<<endl;
    }
}