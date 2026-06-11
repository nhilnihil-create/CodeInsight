#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N,T;
    cin >> N >> T;
    vector<pair<int,int>> H(N);
    rep(i,N) {
        cin >> H[i].first >> H[i].second;
    }
    int tle = 0;
    int costmin = 100000;
    rep(j,N) {
        if (H[j].second <= T ) {
            tle++;
            if (H[j].first < costmin) {
                costmin = H[j].first;
            }
        }
    }
    if (tle == 0) {
        cout << "TLE" << endl;
    }
    else {
        cout << costmin << endl;
    }
}

