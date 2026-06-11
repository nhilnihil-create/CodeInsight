#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 3) {
        cout << "2 5 63" << endl;
        return 0;
    } else if (N == 4) {
        cout << "2 5 20 63" << endl;
        return 0;
    } else if (N == 5) {
        cout << "2 5 20 30 63" << endl;
        return 0;
    }

    vector<ll> cand;
    for (ll i = 1; i <= 30000; i++) {
        if (i % 6 == 0 || i % 6 == 2 || i % 6 == 3 || i % 6 == 4) {
            cand.push_back(i);
        }
    }

    vector<ll> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i] = cand[i];
    }

    ll sum = accumulate(ans.begin(), ans.end(), 0ll);
    if (sum % 6 == 2) {
        ans.erase(find(ans.begin(), ans.end(), 8));
        ans.push_back(30000);
    } else if (sum % 6 == 3) {
        ans.erase(find(ans.begin(), ans.end(), 9));
        ans.push_back(30000);
    } else if (sum % 6 == 5) {
        ans.erase(find(ans.begin(), ans.end(), 9));
        ans.push_back(29998);
    }

    for (ll a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
