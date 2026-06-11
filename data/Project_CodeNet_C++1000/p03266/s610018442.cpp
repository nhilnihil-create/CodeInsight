#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> mod_zero;
    vector<int> mod_half;

    for ( int i = 1; i <= n; i++ ) {
        if ( i % k == 0 ) {
            mod_zero.push_back(i);
        }
        else if ( k % 2 == 0 && i % k == k / 2 ) {
            mod_half.push_back(i);
        }
    }

//    printf("%d %d\n", mod_zero.size(), mod_half.size());

//    rep(i, mod_zero.size()) {
//        cout << mod_zero[i] << endl;
//    }
//    rep(i, mod_half.size()) {
//        cout << mod_half[i] << endl;
//    }

    cout << mod_zero.size() * mod_zero.size() * mod_zero.size() + mod_half.size() * mod_half.size() * mod_half.size() << endl;

    return 0;
}