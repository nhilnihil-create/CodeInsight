#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()

int main(){
    ll x, y;
    cin >> x >> y;
    if(x % y == 0){
        cout << -1 << endl;
    }else{
        cout << x << endl;
    }
    return 0;
}
