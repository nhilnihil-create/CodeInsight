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

vec L(0), R(0),ordL(0), ordR(0);
void mysort(){
    sort(ALL(ordL), [&](ll x, ll y){
        return L[x] > L[y];
    });
    sort(ALL(ordR),[&](ll x, ll y){
        return R[x] < R[y];
    });
    return;
}

ll solve(){
    ll last = L[ordL[0]], numL = 1, numR = 0, res = 0;
    if(last <= 0) return res;
    reps(i,1,N){
        bool r = i%2;
        ll id = r ? ordR[i/2] : ordL[i/2], now = r ? R[id] : L[id];
        if(r && last <= now){
            if(last <= 0) --numL;
            break;
        }else if(!r && now <= last){
            if(last >= 0) --numR;
            break;
        }
        r ? ++numR : ++numL;
        last = now;
    }
    rep(i,numL) res += 2 * L[ordL[i]];
    rep(i,numR) res -= 2 * R[ordR[i]];
    return res;
}

int main(){
    cin>>N;
    rep(i,N){
        cin>>A>>B;
        L.push_back(A);
        R.push_back(B);
    }
    rep(i,N){
        ordL.push_back(i);
        ordR.push_back(i);
    }
    mysort();
    ll ans = solve();
    rep(i,N){
        ll t = R[i];
        R[i] = -L[i];
        L[i] = -t;
        ordR[i] = ordL[i] = i;
    }
    mysort();
    cout<<max(ans, solve())<<endl;
}
