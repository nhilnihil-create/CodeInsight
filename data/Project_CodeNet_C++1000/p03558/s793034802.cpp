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
    matP G(N,vp(0));
    rep(i,N) {
        G[i].emplace_back((i + 1)%N, 1);
        G[i].emplace_back((i * 10)%N, 0);
    }
    deque<P> deq;
    vector<bool> visited(N, false);
    deq.emplace_back(1,1);
    ll ans;
    while(true){
        P p = deq.front();
        deq.pop_front();
        //cout<<p.fi<<' '<<p.se<<endl;
        if(visited[p.fi]) continue;
        visited[p.fi] = true;
        if(p.fi == 0){
            ans = p.se;
            break;
        }
        for(P next : G[p.fi]){
            if(!visited[next.fi]){
                (next.se ? deq.emplace_back(next.fi, p.se + 1) : deq.emplace_front(next.fi, p.se));
            }
        }
    }
    cout<<ans<<endl;
}