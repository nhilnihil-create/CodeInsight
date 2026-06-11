#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll K;
    cin >> K;
    vector<ll> A(K);
    rep(i,K){
        cin >> A[i];
    }
    reverse(A.begin(),A.end());
    ll lb=2,ub=2;
    bool can=true;
    rep(i,K){
        lb=(lb+A[i]-1)/A[i]*A[i];
        ub=(ub/A[i]+1)*A[i];
        if (lb==ub){
            can=false;
            break;
        }
        ub--;
    }
    if (can){
        cout << lb << ' ' << ub << endl;
    }
    else {
        cout << -1 << endl;
    }
}