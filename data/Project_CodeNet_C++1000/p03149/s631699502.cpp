#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 

int main() {
    vector<int> N(4), cnt(4);
    rep(i,4) cin >> N.at(i);
    rep(i,4) {
        if (N.at(i) == 1) ++cnt.at(0);
        if (N.at(i) == 9) ++cnt.at(1);
        if (N.at(i) == 7) ++cnt.at(2);
        if (N.at(i) == 4) ++cnt.at(3);
    }
    rep(i,4) {
        if (cnt.at(i) != 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
