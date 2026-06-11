#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    int N; cin >> N;
    vector<int> vec(N+1);
    rep2(i, 2, N+1) {
        int tmp = i;
        for (int j = 2; j*j <= tmp; j++) {
            while (tmp%j == 0) {
                vec[j]++;
                tmp/=j;
            }
        }
        if (tmp != 1) vec[tmp]++;
    }
    sort(ALL(vec));
    int cnt75 = vec.end() - lower_bound(ALL(vec), 74);
    int cnt25 = (vec.end() - lower_bound(ALL(vec), 24)) * max(0, (int)(vec.end() - lower_bound(ALL(vec), 2) - 1));
    int cnt15 = (vec.end() - lower_bound(ALL(vec), 14)) * max(0, (int)(vec.end() - lower_bound(ALL(vec), 4) - 1));
    int cnt5 = (vec.end() - lower_bound(ALL(vec), 4)) * max(0, (int)(vec.end() - lower_bound(ALL(vec), 4) - 1)) / 2 * max(0, (int)(vec.end() - lower_bound(ALL(vec), 2) - 2));
    int ans = cnt75 + cnt25 + cnt15 + cnt5;
    cout << ans << endl;
    //rep(i, N) cout << vec[i+1] << " ";
    //cout << endl;
}
