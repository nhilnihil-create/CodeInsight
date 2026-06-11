#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    if(S.compare("abc") == 0)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}