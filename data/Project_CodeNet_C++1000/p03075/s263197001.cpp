#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int k;
    cin >> k;
    if (e-a <= k) cout << "Yay!" << endl;
    else cout << ":(" << endl;
    return 0;
}