#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int antenas[5], k;
    rep(0, 5) cin >> antenas[i];
    cin >> k;

    bool impossible = false;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i != j && (antenas[j] - antenas[i] > k)) {
                impossible = true;
                break;
            }
        }
    }

    cout << (impossible ? ":(" : "Yay!") << endl;

    return 0;
}
