#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int64_t> x(N), y(N), z(N);
    for(int i=0; i<N; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }

    int64_t ans = numeric_limits<int64_t>::min();
    for(int bit=0; bit<8; bit++) {
        vector<int64_t> v(N);
        for(int i=0; i<N; i++) {
            v[i] = x[i]*(((bit>>0) & 1) * 2 - 1) + y[i]*(((bit>>1) & 1) * 2 - 1) + z[i]*(((bit>>2) & 1) * 2 - 1);
        }
        sort(v.rbegin(), v.rend());
        ans = max(ans, accumulate(v.begin(), v.begin()+M, 0L));
    }

    cout << ans << endl;
    return 0;
}
