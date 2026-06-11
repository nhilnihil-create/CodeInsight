#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    bool over = 0;
    ll K = in();
    vector<ll> A(K);
    REP(i,K)A[K-i-1] = in();
    ll sh = 2,ue = 2;
    REP(i,K){
        sh = sh % A[i] == 0 ? sh : (sh/A[i])*A[i] + A[i];
        ue = (ue/A[i])*A[i];
        if(sh > ue){
            over = 1;
            break;
        }
        ue = ue + A[i] - 1;
    }
    if(over){
        cout << -1 << "\n";
    }else{
        cout << sh <<" "<< ue << "\n";
    }
}