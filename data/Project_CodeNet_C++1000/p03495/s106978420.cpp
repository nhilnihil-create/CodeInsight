#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;





void one_case() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++mp[a];
    }
    vector<pair<int, int>> a;
    for (auto p : mp) {
        a.pb(p);
    }
    sort(a.begin(), a.end(), [] (auto& l, auto& r) {
        return l.second < r.second;
    });
    int op = 0;
    for (int i = 0; i + k < a.size(); ++i) {
        op += a[i].second;
    }
    cout << op << "\n";
}


int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);


    int t = 1;
//    cin >> t;
    while (t--) {
        one_case();
    }

    return 0;
}
