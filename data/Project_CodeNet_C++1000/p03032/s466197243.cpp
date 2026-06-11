#include <bits/stdc++.h>
using namespace std;
int mxL[200][200], mxR[200][200];
int main() {
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        dq.push_back(a);
    }
    vector<int> vec;
    int cnt = 0;
    for (int i = 1; i <= min(n, k); i++) {
        cnt += dq[i - 1];
        mxL[i][0] = max(mxL[i][0], cnt);
        int lft = k - i;
        vec.push_back(dq[i - 1]);
        sort(vec.begin(), vec.end());
        int tmp = cnt;
        for (int j = 0; j < min(lft, (int)vec.size()); j++) {
            tmp -= vec[j];
            mxL[i][j + 1] = max(mxL[i][j + 1], tmp);
        }
    }
    reverse(dq.begin(), dq.end());
    cnt = 0;
    vec.clear();
    for (int i = 1; i <= min(n, k); i++) {
        cnt += dq[i - 1];
        mxR[i][0] = max(mxR[i][0], cnt);
        int lft = k - i;
        vec.push_back(dq[i - 1]);
        sort(vec.begin(), vec.end());
        int tmp = cnt;
        for (int j = 0; j < min(lft, (int)vec.size()); j++) {
            tmp -= vec[j];
            mxR[i][j + 1] = max(mxR[i][j + 1], tmp);
        }
    }
    int res = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= i; j++) {
            for (int q = 0; q <= k; q++) {
                for (int w = 0; w <= q; w++) {
                    int cntL = i - j, cntR = q - w;
                    if (i + q > n) continue;
                    if (i + j + q + w > k) continue;
                    res = max(res, mxL[i][j] + mxR[q][w]);
                    //cout << i << ' ' << j << ' ' << q << ' ' << w << ' ' << mxL[i][j] + mxR[q][w] << '\n';
                }
            }
        }
    }
    cout << res;
    return 0;
}