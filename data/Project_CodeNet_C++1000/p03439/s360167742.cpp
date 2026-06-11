#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    
    auto get_state = [](int i) {
        cout << i << "\n" << flush;
        string s;
        cin >> s;
        if ( s == "Male" ) return 0;
        else if ( s == "Female" ) return 1;
        else return -1;
    };

    int ls = get_state(0);
    if ( ls < 0 ) return;
    int rs = 1 - ls; 
    int l = 0, r = N;
    while ( r - l > 0 ) {
        int m = (l+r)/2;
        int ms = get_state(m);
        if ( ms < 0 ) return;
        if ( (ms^ls) == ((m^l)&1) ) {
            l = m;
            ls = ms;
        } else {
            r = m;
            rs = ms;
        }
    }
    return;
}

int main() {
    solve();
    return 0;
}