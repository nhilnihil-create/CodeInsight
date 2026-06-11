#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<string> s(N + 1);
    cout << "0\n";
    cin >> s[0];
    s[N] = s[0];
    int m = 0, l = 0, r = N;
    while (s[m] != "Vacant") {
        m = (l + r) / 2;
        cout << m << endl;
        cin >> s[m];
        if ((m - l) % 2 ^ s[m] == s[l]) {
            l = m;
        } else {
            r = m;
        }
    }
}