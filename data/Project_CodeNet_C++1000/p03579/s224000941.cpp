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

bool d2 = true;
vec group(100010, 0);
mat G(100010, vec(0));
void dfs(ll v, ll c){
    group[v] = c;
    for(ll to : G[v]){
        if(group[to] == c){
            d2 = false;
            return;
        }else if(group[to] == 0){
            dfs(to, -c);
        }
    }
    return;
}

int main() {
    cin>>N>>M;
    rep(i,M){
        cin>>A>>B;
        --A; --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    dfs(0, 1);
    if(!d2){
        cout<<N * (N - 1) / 2 - M<<endl;
    }else{
        ll a, b;
        a = b = 0;
        rep(i,N) (group[i] > 0 ? ++a : ++b);
        cout<<a * b - M<<endl;
    }
}