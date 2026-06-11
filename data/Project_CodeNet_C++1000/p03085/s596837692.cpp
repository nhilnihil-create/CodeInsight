#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    string a;
    cin >> a;
    if (a == "A") {
        cout << "T" << endl;
        return 0;
    };
    if (a == "T") {
        cout << "A" << endl;;
        return 0;
    };
    if (a == "C") {
        cout << "G" << endl;
        return 0;
    };
    cout << "C" << endl;
}