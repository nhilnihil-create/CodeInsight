#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
    Int N;
    cin >> N;
    vector<bool> used(30010,false);
    Int sum = 0;
    vector<Int> ans(N,0);

    if (N <= 5) {
        ans[0] = 2;
        ans[1] = 3;
        if (N >= 4) {
            ans[2] = 4;
            ans[3] = 9;
        }
    }
    if (N == 3) ans[2] = 25;
    if (N == 5) ans[4] = 6;

    if (N >= 6) {
        rep(i,N) {
            if (i%2==0) {
                Int now = 3 * (i / 2) + 1;
                if (now % 2 == 1) now++;
                ans[i] = now;
                sum += now;
                used[now] = true;
            }
            if (i%2==1) {
                Int now = 3 * ((i + 1)/2);
                ans[i] = now;
                sum += now;
                used[now] = true;
            }
        }

        if (sum % 6 == 2) {
            Int now;
            for (int i = 30000; i > 0; i -= 6) {
                if (!used[i]) {
                    now = i;
                    break;
                }
            }
            ans[4] = now;
        }

        if (sum % 6 == 5) {
            Int now;
            for (int i = 29998; i > 0; i -= 6) {
                if (!used[i]) {
                    now = i;
                    break;
                }
            }
            ans[5] = now;
        }

        if (sum % 6 == 3) {
            Int now;
            for (int i = 30000; i > 0; i -= 6) {
                if (!used[i]) {
                    now = i;
                    break;
                }
            }
            ans[5] = now;
        }
    }

    rep(i,N-1) cout << ans[i] << " ";
    cout << ans[N-1] << endl;


}