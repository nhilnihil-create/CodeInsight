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

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main() {
    cin>>N;
    vec a(N);
    rep(i,N) cin>>a[i];
    ll sum = 0;
    rep(i,N) sum += a[i];
    bitset<ll(4e+6 + 1)> bs(1);
    rep(i,N) bs = bs | (bs<<a[i]);
    reps(i, (sum + 1)/2, sum + 1){
        if(bs[i]) {
            cout<<i<<endl;
            return 0;
        }
    }
}