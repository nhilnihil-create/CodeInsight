#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

    ll a, b, k;
    cin >> a >> b >> k;

    rep(i, k){
        if(i%2 == 0){
            if(a&1) --a;
            a /= 2;
            b += a;
        }
        else{
            if(b&1) --b;
            b /= 2;
            a += b;
        }
    }
    cout << a << " " << b << endl;

    return 0;
}