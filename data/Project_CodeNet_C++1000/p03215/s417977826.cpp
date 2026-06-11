#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> sums(N + 1);
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        sums[i + 1] = sums[i] + a;
    }
    //set<vector<int>> bin;
    //map<vector<int>, int> cnt;
    int ct = 0;
    vector<vector<int>> biny(N * (N + 1) / 2, vector<int>(41));
    for (int i = 0; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            ll temp = sums[j] - sums[i];
            //vector<int> arr(41);
            for (int k = 0; temp > 0; k++) {
                biny[ct][k] = temp % 2;
                temp /= 2;
            }
            ct++;
        }
    }

    ll ans = 0, twos = pow(2, 40);
    for (int i = 40; i >= 0; i--) {
        ll tot = 0;
        for (int j = 0;j<N*(N+1)/2;j++) {
            if (biny[j][i] == 1) tot ++;
        }
        if (tot >= K) {
            ans += twos;
            for (int k = 0; k < N * (N + 1) / 2; k++) {
                if (biny[k][i] == 0) {
                    //cnt[y] = 0;
                    //bin.erase(y);
                    biny[k] = vector<int>(41);
                }
            }
        }
        twos /= 2;
    }
    cout << ans << endl;
}
