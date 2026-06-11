#include <bits/stdc++.h>
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

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 50;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

ll dia = 0;
vector<bool> used(200010,false);
mat G(200010,vec(0));
ll dfs(ll v){
    used[v] = true;
    ll f, s;
    f = s = 0;
    for(ll to: G[v]){
        if(!used[to]){
            ll temp = dfs(to);
            if(temp >= f){
                s = f;
                f = temp;
            }else if(temp >= s){
                s = temp;
            }
        }
    }
    dia = max(dia, f + s);
    return f + 1;
}

int main() {
    cin>>N;
    rep(i,N - 1){
        cin>>A>>B;
        --A; --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    dfs(0);
    cout<<(dia%3 == 1 ? "Second" : "First")<<endl;
    //cout<<dia<<endl;
}