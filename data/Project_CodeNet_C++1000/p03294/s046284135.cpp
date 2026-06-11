#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    ll res = 0;
    rep(i, N) {
        cin >> A[i];
        res += (A[i] - 1);
    }

    cout << res << endl;
}