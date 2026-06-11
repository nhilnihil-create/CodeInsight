#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    for ( ll i = 0; i < N; ++i){
        cin >> A[i];
    }
    
    ll x;
    ll sho, amari;
    sho = ( N - K ) / ( K - 1 );
    amari = ( N - K ) % ( K - 1 );
    x = sho + 1;
    if ( amari != 0 ) ++x;
    
    cout << x << endl;
    
    return 0;
}
