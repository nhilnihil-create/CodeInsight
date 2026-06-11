#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<ll> A, B, C, D, BS, DS;
string S;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

signed main(){
    cin >> S;
    A.resize(S.size(),0);
    B.resize(S.size(),0);
    C.resize(S.size(),0);
    D.resize(S.size(),0);
    for(int i=0;i<S.size();i++) {
        if(S[i]=='A'){
            A[i]++;
            continue;
        }
        if(S[i]=='B'){
            B[i]++;
            BS.push_back(i);
            continue;
        }
        if(S[i]=='C'){
            C[i]++;
            continue;
        }
        D[i]++;
        DS.push_back(i);
    }
    for(int i=0;i<S.size()-1;i++) {
        A[i+1] = A[i+1] + A[i];
        B[i+1] = B[i+1] + B[i];
        C[i+1] = C[i+1] + C[i];
        D[i+1] = D[i+1] + D[i];
    }
    for(int i=0;i<BS.size();i++) {
        if(BS[i]-1>=0) {
            ans += modpow(3,D[S.size()-1],MOD)*A[BS[i]-1]*(C[S.size()-1]-C[BS[i]]);
            ans += modpow(3,D[S.size()-1]-1,MOD)*A[BS[i]-1]*(D[S.size()-1]-D[BS[i]]);
            ans += modpow(3,D[S.size()-1]-1,MOD)*D[BS[i]-1]*(C[S.size()-1]-C[BS[i]]);
            ans += modpow(3,D[S.size()-1]-2,MOD)*D[BS[i]-1]*(D[S.size()-1]-D[BS[i]]);
            ans %= MOD;
            //cout << ans << endl;
        }
    }
    for(int i=0;i<DS.size();i++) {
        if(DS[i]-1>=0) {
            ans += modpow(3,D[S.size()-1]-1,MOD)*A[DS[i]-1]*(C[S.size()-1]-C[DS[i]]);
            ans += modpow(3,D[S.size()-1]-2,MOD)*D[DS[i]-1]*(C[S.size()-1]-C[DS[i]]);
            ans += modpow(3,D[S.size()-1]-2,MOD)*A[DS[i]-1]*(D[S.size()-1]-D[DS[i]]);
            ans += modpow(3,D[S.size()-1]-3,MOD)*D[DS[i]-1]*(D[S.size()-1]-D[DS[i]]);
            ans %= MOD;
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}