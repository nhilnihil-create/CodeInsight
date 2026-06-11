#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    vector<bool> prime(55556, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= 55555; i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= 55555; j += i) {
                prime[j] = false;
            }
        }
    }
    //rep(i, 55556) if (prime[i]) cout << i << " ";
    //vector<int> count(5, 0);
    //rep(i, 55556) if (prime[i]) count[i % 5]++;
    //rep(i, 5) cout << count[i] << "\n";
    vector<int> ans;
    rep(i, 55556) if (prime[i] && i % 5 == 1) ans.push_back(i);
    int N;
    cin >> N;
    rep(i, N) {
        cout << ans[i];
        if (i == N - 1) cout << "\n";
        else cout << " ";
    }
}