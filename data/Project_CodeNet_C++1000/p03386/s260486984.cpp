#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    ll a, b, k;
    cin >> a >> b >> k;

    for (ll i=a; i<=min(b, a+k-1); i++){
        out(i);
    }
    for (ll i=max(b-k+1, a+k); i<=b; i++){
        out(i);
    }
    return 0;

}