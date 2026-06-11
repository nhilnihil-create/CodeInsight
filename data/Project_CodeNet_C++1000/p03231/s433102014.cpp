#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

ll gcd(ll a, ll b){
    ll r,temp;
    if (a < b){
        temp = a;
        a = b;
        b = temp;
    }
    while ( (r = a % b) != 0){
        a = b;
        b = r;
    }
    return b;
}

int main(){
    ll N,M;
    cin >> N >> M;
    string S,T;
    cin >> S >> T;
    ll x = gcd(N, M);
    ll Nx = N / x;
    ll Mx = M / x;
    ll N_now = 0;
    ll M_now = 0;
    bool possible = true;
    for (ll i = 1; i <= x; i++){
        if (S[N_now] != T[M_now]) possible = false;
        N_now += Nx;
        M_now += Mx;
    }
    if (!possible) cout << -1 << endl;
    else cout << N * M / x << endl;
}
