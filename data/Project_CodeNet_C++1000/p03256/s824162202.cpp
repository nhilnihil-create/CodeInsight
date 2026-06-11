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
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>N>>M>>S;
    mat ab(N, vec(2,0)), G(N, vec(0));
    rep(i,M){
        cin>>A>>B;
        --A; --B;
        G[B].push_back(A);
        G[A].push_back(B);
        ++ab[A][S[B] - 'A'];
        ++ab[B][S[A] - 'A'];
    }
    vector<bool> del(N,false);
    queue<ll> que;
    rep(i,N){
        rep(j,2){
            if(ab[i][j] == 0 && !del[i]) {
                del[i] = true;
                que.push(i);
            }
        }
    }
    while(!que.empty()){
        ll v = que.front(), c = S[v] - 'A';
        que.pop();
        for(ll to : G[v]){
            if(!del[to]){
                if(--ab[to][c] == 0){
                    del[to] = true;
                    que.push(to);
                }
            }
        }
    }
    ll ans = N;
    rep(i,N) ans -= del[i];
    cout<<(ans == 0 ? "No" : "Yes")<<endl;
}