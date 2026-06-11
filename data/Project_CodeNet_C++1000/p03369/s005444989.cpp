#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

int main() {
    string s; cin >> s;
    cout << 700 + count(s.begin(), s.end(), 'o') * 100 << endl;
}