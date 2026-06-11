#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    ll N, M, d, t;
    cin >> N;
    map<int, int> mpD;
    rep(i,N) {
        cin >> d;
        ++mpD[d];
    }
    cin >> M;
    map<int, int> mpT;
    rep(i,M) {
        cin >> t;
        ++mpT[t];
    }
    for (auto x : mpT) {
        if (x.second > mpD[x.first]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}

