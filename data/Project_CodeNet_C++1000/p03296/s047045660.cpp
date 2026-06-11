#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    
    int ans = 0;
    REP(i, N) {
        if (a[i] == a[i - 1]) {
            ++ans;
            a[i] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
