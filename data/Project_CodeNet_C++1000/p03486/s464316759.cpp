#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;





void one_case() {
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    for (int i = 0; i < min(t.size(), s.size()); ++i) {
        if (s[i] > t[i]) {
            cout << "No\n";
            return;
        }
        if (s[i] < t[i]) {
            cout << "Yes\n";
            return;
        }
    }

    if (s.size() < t.size()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

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
