#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    vector<int> vec(3);
    rep(i, 3) cin >> vec[i];

    if (vec[0] == vec[1] && vec[1] == vec[2]) {
        puts("Yes");
    } else {
        puts("No");
    }
}