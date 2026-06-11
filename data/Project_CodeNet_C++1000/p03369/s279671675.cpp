#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    cin >> S;
    int o = 0;
    if (S[0] == 'o') o++;
    if (S[1] == 'o') o++;
    if (S[2] == 'o') o++;
    cout << 700 + 100 * o << endl;
}
