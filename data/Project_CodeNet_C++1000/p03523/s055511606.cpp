#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    string S;
    cin >> S;
    regex M ("A?KIHA?BA?RA?");
    cout << ((regex_match(S , M)) ? "YES" : "NO") << endl;
}
