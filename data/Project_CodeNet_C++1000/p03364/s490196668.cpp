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

vector<string> G(0);
bool ok(int d){
    rep(i,N){
        int k = (d + i) % N;
        rep(j,N){
            if(G[i][j] != G[(j + N - d)%N][k]) return false;
        }
    }
    return true;
}

int main(){
    cin>>N;
    rep(i,N) cin>>S, G.push_back(S);
    ll ans = 0;
    rep(i,N){ //
        if(ok(i)) ans += N;
    }
    cout<<ans<<endl;
}