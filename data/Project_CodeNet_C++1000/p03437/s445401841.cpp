#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int x;
    int y;
    cin >> x >> y;
    if(x%y == 0) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
}