#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;





void one_case() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++mp[a];
    }
    int res = 0;
    for (auto p : mp) {
        if (p.second < p.first) {
            res += p.second;
        } else {
            res += p.second - p.first;
        }

    }
    cout << res << "\n";

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
