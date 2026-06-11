#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


int main(){
    ll N ,M;
    cin >> N >> M;
    vector<ll> A(M,0);
    vector<ll> D(M - 1,0);
    for(int i = 0; i < M; i++) cin >> A[i];
    sort(A.begin() , A.end());
    for(int i = 0; i < M - 1; i++){
        D[i] = abs(A[i + 1] - A[i]);
    }
    sort(D.begin() ,D.end(),greater<ll>());
    ll ans = 0;
    for(int i = 0 + (N - 1); i < M - 1; i++){
        ans += D[i];
    }
    cout << ans << endl;
    
}
