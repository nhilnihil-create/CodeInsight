#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<ll>divisor(ll n){
    vector<ll>ret;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            ret.push_back(i);
            if(i*i!=n)ret.push_back(n/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}

int main(){
    ll n,m;
    cin >> n >> m;
    auto div = divisor(m);
    sort(div.rbegin(),div.rend());
    rep(i,div.size()){
        if(div[i]*n<=m){
            cout << div[i] << endl;
            return 0;
        }
    }

    return 0;
}
