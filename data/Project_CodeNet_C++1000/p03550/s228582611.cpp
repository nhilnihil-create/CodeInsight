#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// 400012- 128


void oneCase() {
    int n,z, w;
    cin >> n >> z >> w;
    vector<int> a(n);

    for (auto& el : a) {
        cin >> el;
    }
    if (n == 1) {
        cout << abs(a[0] - w) << "\n";
        return;
    }
    cout << max(abs(a.back() - w), abs(a[n - 1] - a[n - 2])) << "\n";
}

int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
       oneCase();
    }

    return 0;
}
