#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> A(N),G(N+1);
    map<ll,ll> amari;
    rep(i,N){
        cin >> A[i];
        G[i+1] = G[i] + A[i];
        amari[G[i+1]%M]++;
    }
    amari[0]++;
    ll ans = 0;
    rep(i,N+1){
        if(amari[G[i]%M]>0){
            ans += amari[G[i]%M]*(amari[G[i]%M]-1)/2;
            amari[G[i]%M]=0;
        }
    }
    cout << ans << endl;
    return 0;
}