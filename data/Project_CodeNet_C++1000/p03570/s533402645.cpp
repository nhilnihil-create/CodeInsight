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
    cin>>S;
    N = S.size();
    set<ll> est;
    est.insert(0);
    map<ll,ll> num;
    num[0] = 0;
    ll now = 0;
    rep(i,N){
        ll alph = S[i] - 'a', res = INF;
        now = now ^ (1LL<<alph);
        //cout<<now<<endl;
        rep(j,26){
            if(est.find(now ^ (1LL<<j)) != est.end()) {
                res = min(res, num[now ^ (1LL << j)] + 1);
            }
        }
        if(est.find(now) != est.end()){
            res = min(res, num[now]);
        }
        est.insert(now);
        num[now] = res;
    }
    cout<<(num[now] == 0 ? 1 : num[now])<<endl;
    //rep(i,27) cout<<num[(1LL<<i) - 1]<<endl;
}