#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for(int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for(int i = ((int)(n)); i > 0; --i)
#define INF 100000000

using namespace std;

int main() {
    int res = INF;
    int n;
    cin >> n;
    vector<int> abcs(3);
    rep(i, 3) cin >> abcs[i];
    vector<int> l(n);
    for(int i = 0; i < n; i++)
        cin >> l[i];

    vector<int> bits(3);
    for(bits[0] = 1; bits[0] < (1 << n); ++bits[0]) {
        for(bits[1] = 1; bits[1] < (1 << n); ++bits[1]) {
            if(bits[0] & bits[1])
                continue;
            for(bits[2] = 1; bits[2] < (1 << n); ++bits[2]) {
                if(bits[0] & bits[2] || bits[2] & bits[1])
                    continue;
                vector<int> sums(3), nums(3, 0);
                rep(i, n) {
                    rep(j, 3) {
                        if(bits[j] >> i & 1) {
                            sums[j] += l[i];
                            nums[j]++;
                        }
                    }
                }
                int score = 0;
                rep(i, 3) {
                    score += abs(abcs[i] - sums[i]);
                    score += (nums[i] - 1) * 10;
                }
                res = min(res, score);
            }
        }
    }
    cout << res << endl;
    return 0;
}