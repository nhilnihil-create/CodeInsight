#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    vector<int> a(3);
    rep(i, 3) cin >> a[i];
    sort(a.rbegin(), a.rend());
    cout << a[0] * 10 + a[1] + a[2] << endl;
    return 0;
}
