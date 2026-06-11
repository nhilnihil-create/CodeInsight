#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    ll N,D,X;
    cin >> N >> D >> X;
    vector<int> V(N);
    rep(i,N) {
        cin >> V[i];
    }
    int ans = X;
    rep(j,N) {
        int t = 1;
        int count = 0;
        while (t <= D) {
            count++;
            t += V[j];
        }
        ans += count;
    }
    cout << ans << endl;
}

