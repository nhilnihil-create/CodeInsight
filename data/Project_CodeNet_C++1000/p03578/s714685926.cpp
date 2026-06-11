#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, m;
    cin >> n;
    unordered_map<ll, int> counter;
    rep(i, n) {
        ll d;
        cin >> d;
        ++counter[d];
    }
    cin >> m;
    rep(i, m){
        ll t;
        cin >> t;
        if(counter[t]-- <= 0){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}