#include <bits/stdc++.h>
#define rep(i, a) for(int i = 0; i < a; i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i, n) {
        cin >> l[i];
    }
    sort(l.begin(), l.end());
    int a = 0;
    rep(i, n - 1) a += l[i];
    cout << ((l[n - 1] < a) ? "Yes" : "No") << endl;
}