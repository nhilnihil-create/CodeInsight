#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    float n = s.size();

    set<string> subs;
    for (int i = 1; i <= 5; i++) {
        rep(j, n - i + 1) {
            string sub = s.substr(j, i);
            subs.insert(sub);
        }
    }

    int i = 1;
    for (auto sub : subs) {
        if (i == k) {
            cout << sub << endl;
            break;
        }
        i++;
    }

    return 0;
}
