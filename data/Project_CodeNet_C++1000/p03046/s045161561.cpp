#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;

int main(){
    int M;
    ll K;
    cin >> M >> K;
    ll e[M+1];
    e[0] = 1;
    rep(i, M) e[i+1] = 2*e[i];
    if(M == 0){
        if(K == 0) cout << 0 << ' ' << 0 << endl;
        else cout << -1 << endl;
    }
    elif(M == 1){
        if(K == 0) cout << 0 << ' ' << 0 << ' ' << 1 << ' ' << 1 << endl;
        else cout << -1 << endl;
    }
    else{
        if(K < e[M]){
            cout << K << ' ';
            rep(i, e[M]){
                if(i != K) cout << i << ' ';
            }
            cout << K << ' ';
            rep3(i, e[M]-1, 0){
                if(i != K) cout << i << ' ';
            }
            cout << endl;
        }
        else cout << -1 << endl;
    }
}