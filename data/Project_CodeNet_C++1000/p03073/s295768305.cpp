#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

using ll = long long;

int main() {
    // freopen('b.txt', 'r', stdin);
    // fastio;

    string S;
    cin >> S;

    int n = S.size();

    string s1, s2;
    for (int i = 0; i < n; i ++) {
        if (i % 2 == 0)
            s1 += '0', s2 += '1';
        else
            s2 += '0', s1 += '1';
    }

    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i ++) {
        if (S[i] != s1[i])
            d1 ++;
        if (S[i] != s2[i])
            d2 ++;
    }

    cout << min(d1, d2) << '\n';

    return 0;
}

