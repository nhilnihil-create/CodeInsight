#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    map<string, string> mp;
    mp["A"] = "T";
    mp["T"] = "A";
    mp["G"] = "C";
    mp["C"] = "G";

    cout << mp[s] << endl;
    return 0;
}