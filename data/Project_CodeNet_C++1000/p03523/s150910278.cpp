#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    string S;
    cin >> S;
    regex r( R"(^A?KIHA?BA?RA?$)" );
    return regex_match(S,r);
}

int main() {
    string ans = solve() ? "YES" : "NO";
    cout << ans << "\n";
    return 0;
}