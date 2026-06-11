#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N; cin >> N;
    int topB = 0, botA = 0;
    ll ans = 0;
    bool non = true;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (s[0] == 'B' ^ s[s.length()-1] == 'A') non = false;
        if (s[0] == 'B') topB++;
        if (s[s.length()-1] == 'A') botA++;
        for (int i = 0; i < s.length()-1; i++) {
            if (s[i] == 'A' && s[i+1] == 'B') ans++;
        }
    }
    cout << ans + (min(topB, botA)) - (int)(topB == botA && non && topB > 0) << endl;
}
