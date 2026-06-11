#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 10007;
const int inf = 101234567;

int main() {
    ll N, M;
    cin >> N >> M;
    ll ans = 1;
    vector<int>yakusu;

    for (int i = 1; i < sqrt(M); i++) {
        if (M % i == 0) {
            yakusu.push_back(i);
            yakusu.push_back(M/i);
        } 
    }
    if ((int)sqrt(M) == sqrt(M)) {
        yakusu.push_back(sqrt(M));
    }
    sort(yakusu.begin(), yakusu.end());

    auto itr = lower_bound(yakusu.begin(), yakusu.end(), N);
    ans = M / *itr;

    cout << ans << endl;
}
