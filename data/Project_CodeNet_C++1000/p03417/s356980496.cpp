#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M; cin >> N >> M;
    ll ans;
    if(N>1 && M>1) ans = N*M - 2*M - 2*N + 4;
    else if((N==1 && M>1) || (M==1 && N>1)) ans = N*M - 2;
    else ans = 1;
    cout << ans << endl;    
}