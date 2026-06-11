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

void solve(){
    ll mnum, cnum, res, plus;
    mnum = cnum = res = plus = 0;
    rep(i,N*2){
        if(T[i] == 'C'){
            --cnum;
        }else if(T[i] == 'M'){
            --mnum;
            plus -= cnum;
        }else if(T[i] == 'D'){
            res += plus;
        }
        if(T[i+K] == 'C'){
            ++cnum;
            plus += mnum;
        }else if(T[i+K] == 'M'){
            ++mnum;
        }
    }
    cout<<res<<endl;
}

int main() {
    cin>>N>>S>>Q;
    T = "";
    rep(i,N) T.push_back('Z');
    S.append(T);
    T.append(S);
    rep(i,Q){
        cin>>K;
        solve();
    }
}