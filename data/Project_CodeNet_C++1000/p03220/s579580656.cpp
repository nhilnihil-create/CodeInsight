#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    int N,T,A;
    cin >> N >> T >> A;
    vector<int> H(N);
    rep(i,N) {
        cin >> H[i];
    }
    double min = 100000;
    int ans;
    rep(j,N) {
        if (abs(A - (T - 0.006*H[j])) < min) {
            min = abs(A - (T - 0.006*H[j]));
            ans = j + 1;
        }
    }
    cout << ans << endl;
}

