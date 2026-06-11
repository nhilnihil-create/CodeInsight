#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;

    int k = S.size() / 2;
    int c = S[k];
    int l = -1;
    int r = 0;
    int len = 0;
    if (S.size() % 2) l = 0;
    while (k + l >= 0 && S[k + l] == c && S[k + r] == c) {
//        cout << k + l << ":" << k + r << endl;
        l--;
        r++;
        len++;
    }

    cout << k + len << endl;
}