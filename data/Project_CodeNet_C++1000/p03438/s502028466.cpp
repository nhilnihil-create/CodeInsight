#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    
    long long a_sum = 0, b_sum = 0;
    rep(i, N) a_sum += a[i];
    rep(i, N) b_sum += b[i];
    long long a_cnt = 0, b_cnt = 0;
    rep(i, N) {
        int k = max((b[i] - a[i] + 1) / 2, 0);
        a[i] += k * 2;
        a_cnt += k;
    }
    rep(i, N) {
        int k = a[i] - b[i];
        b[i] += k;
        b_cnt += k;
    }
    if (a_cnt > b_sum - a_sum || b_cnt > b_sum - a_sum) {
        cout << "No\n";
        return 0;
    }
    if (b_sum - a_sum - b_cnt == (b_sum - a_sum - a_cnt) * 2) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
