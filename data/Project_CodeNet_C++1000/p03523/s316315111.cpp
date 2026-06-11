#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    string S;
    cin >> S;
    vector<string> vec = {"AKIHABARA", "AKIHBARA", "AKIHABRA", "AKIHABAR", "AKIHBRA", "AKIHBAR", "AKIHBR", "AKIHABR", "KIHBR", "KIHBRA", "KIHBAR", "KIHBARA", "KIHABR", "KIHABRA", "KIHABAR", "KIHABARA"};
    for (string a : vec) {
        if (a == S) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}