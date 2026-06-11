#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector <int> v(n);
    rep(i,n) cin >> v[i];
    sort(v.begin(), v.end());
    cout << *(v.end()-1)-*(v.begin()) << endl;
}
