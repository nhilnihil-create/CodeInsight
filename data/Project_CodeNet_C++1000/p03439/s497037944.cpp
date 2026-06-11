#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> a(N + 1, "?");
    string s;
    cout << "0\n";
    cin >> s;
    if (s == "Vacant") return 0;
    a[0] = s;
    a[N] = s;
    int i = 0, l = 0, r = N;
    while (true) {
        i = (l + r) / 2;
        cout << i << "\n";
        cin >> s;
        if (s == "Vacant") return 0;
        a[i] = s;
        if (s == a[l]) {
            if ((i - l) % 2 == 1) r = i;
            else l = i;
        } else {
            if ((i - l) % 2 == 1) l = i;
            else r = i;
        }
    }
}