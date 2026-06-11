#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll div2 ( ll x ){
    ll count = 0;
    while ( x % 2 == 0 ){
        x = x / 2;
        ++ count;
    }
    return count;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for ( ll i = 0; i < N; ++i){
        cin >> a[i];
    }
    
    ll all = 0;
    for ( ll i = 0; i < N; ++i){
        all += div2(a[i]);
    }
    
    cout << all << endl;
    
    return 0;
}
