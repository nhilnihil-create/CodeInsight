#include <bits/stdc++.h>
#include <bitset>
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

int main(){
    cin>>N>>K;
    vec a(N);
    rep(i,N) cin>>a[i];
    rep(i,N) {
        ll temp = a[i];
        reps(j, i + 1, N) {
            temp += a[j];
            a.push_back(temp);
        }
    }
    vector<vector<bool> > can_use(2, vector<bool>(N * (N + 1) / 2, true));
    ll ans = 0;
    Rrep(i,41){
        ll num = 0;
        rep(j, N * (N + 1) / 2){
            if(can_use[0][j] && (a[j]>>i)&1){
                ++num;
                can_use[1][j] = true;
            }else{
                can_use[1][j] = false;
            }
        }
        if(num >= K){
            swap(can_use[0], can_use[1]);
            ans += (1LL<<i);
        }
    }
    cout<<ans<<endl;
}