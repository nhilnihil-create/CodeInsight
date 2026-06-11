//#include<atcoder/all>
//using namespace atcoder;

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N; cin >> N;
    int pt = 0; int pp[2] = { 0,0 };
    bool ok = true;
    rep(i, N) {
        int t, p[2]; cin >> t >> p[0] >> p[1];
        int d = abs(p[0] - pp[0]) + abs(p[1] - pp[1]);
        if (d > t - pt) ok = false;
        if (d % 2 != (t - pt) % 2) ok = false;
        pt = t; pp[0] = p[0]; pp[1] = p[1];
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}