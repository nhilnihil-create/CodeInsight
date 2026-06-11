#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    if(S == "abc") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
