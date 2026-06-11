#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    string S; cin >> S;
    string T = "AKIHABARA";
    int i = 0;
    for (int j = 0; j < T.size(); j++) {
        if (i < S.size() && S[i] == T[j]) {
            i++;
        } else if (T[j] == 'A') {
        } else {
            goto FAIL;
        }
    }
    if (i != S.size()) goto FAIL;
    cout << "YES\n"; return 0;
    FAIL: cout << "NO\n";
    return 0;
}