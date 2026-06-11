#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll m, k;
    cin >> m >> k;
    if(m <= 1) {
        if(k == 0) {
            rep(i, 0, 1LL<<(m+1)) cout << i/2 << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        if(k < 1LL<<(m)) {
            rep(i, 0, 1LL<<(m)) if(i != k) cout << i << " ";
            cout << k << " ";
            for(ll i = (1LL<<(m))-1; i >= 0; i--) if(i != k) cout << i << " ";
            cout << k << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}