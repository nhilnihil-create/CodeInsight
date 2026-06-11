#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// 400012- 128


void oneCase() {
    int n, m;
    cin >> n >> m;
    cout << ((n - m) * 100 + m * 1900) * (1 << m) << "\n";
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
