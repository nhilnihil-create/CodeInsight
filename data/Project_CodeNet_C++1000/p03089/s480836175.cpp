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
    vector<int> ans;
    rep(i, N) { cin >> A[i]; }

    while (A.size() != 0) {
        vector<pair<int, int>> vec;
        rep(i, A.size()) {
            if (A[i] - (i + 1) == 0)
                vec.push_back({A[i], i});
        }
        sort(all(vec), greater<pair<int, int>>());
        if (vec.size() == 0) {
            cout << -1 << endl;
            return 0;
        }

        ans.push_back(vec[0].first);
        A.erase(A.begin() + vec[0].second);
    }

    reverse(all(ans));
    for (auto a : ans) {
        cout << a << endl;
    }
}