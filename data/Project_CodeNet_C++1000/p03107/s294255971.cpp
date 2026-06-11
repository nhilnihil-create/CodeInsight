#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    map<char, int> a;
    for (int i = 0; i < S.length(); i++) {
        a[S[i]]++;
    }
    cout << min(a['0'], a['1']) * 2 << endl;

    return 0;
}
