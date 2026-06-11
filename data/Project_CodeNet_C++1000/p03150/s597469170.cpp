#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int keysize = 7;
const string keyence = "keyence";

int main() {
    string S; cin >> S;

    if (S == keyence) {
        cout << "YES" << endl;
        return 0;
    }

    if (S.size() < keysize) {
        cout << "NO" << endl;
        return 0;
    }

    if (S.substr(0, keysize) == keyence || S.substr(S.size() - keysize, keysize) == keyence) {
        cout << "YES" << endl;
        return 0;
    }

    int r = 0, l = 0;
    for (int i = 1; i <= keysize; i++) if (S.substr(0, i) == keyence.substr(0, i)) r = i;
    for (int i = 1; i <= keysize; i++) if (S.substr(S.size() - i, i) == keyence.substr(keysize - i, i)) l = i;
    if (r + l >= keysize) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}