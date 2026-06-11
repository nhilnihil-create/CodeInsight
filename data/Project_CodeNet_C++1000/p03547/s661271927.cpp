#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// 400012- 128


void oneCase() {
    char a, b;
    cin >> a >> b;
    if (a > b) {
        cout << ">\n";
    } else if (a < b) {
        cout << "<\n";
    } else {
        cout << "=\n";
    }

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
