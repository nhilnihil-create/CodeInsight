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
    cin>>N>>M;
    ll pa = -1, nm = N + M - 1;
    mat G(N, vec(0));
    vec num_in(N, 0), ans(N,0);
    rep(i,nm){
        cin>>A>>B;
        --A, --B;
        G[A].push_back(B);
        ++num_in[B];
    }
    rep(i,N) if(num_in[i] == 0) pa = i;
    queue<ll> que;
    que.push(pa);
    ans[pa] = -1;
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(ll to : G[v]){
            --num_in[to];
            if(num_in[to] == 0){
                ans[to] = v;
                que.push(to);
            }
        }
    }
    rep(i,N) cout<<ans[i] + 1<<endl;
}