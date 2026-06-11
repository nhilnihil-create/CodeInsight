// 7/10
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int N, A[3];
vector<int> l;
vector<int> p;

int dfs(int i = 0) {
    int ret = INT32_MAX;

    if (i == N) {
        // cout << "--------------------------" << endl;
        // for (auto q : p) cout << q;
        // cout << endl;

        int use = 0;
        int sm[3] = {0};

        rep(i, N) {
            if (p[i] != 3) {
                sm[p[i]] += l[i];
                use++;
            }
        }

        // printf("sm[0], sm[1], sm[2] = %d, %d, %d\n", sm[0], sm[1], sm[2]);

        // 合成魔法はMP10を消費
        ret = (use - 3) * 10;

        // あとはA, B, Cに延長 or 短縮を使って合わせる
        rep(i, 3) {
            if (sm[i] == 0) return INT32_MAX;
            ret += abs(sm[i] - A[i]);
        }

        return ret;
    }

    // i番目はA（0）に使う
    // p.push_back(0);
    p[i] = 0;
    ret = min(ret, dfs(i + 1));

    // i番目はB（1）に使う
    // p.pop_back();
    // p.push_back(1);
    p[i] = 1;
    ret = min(ret, dfs(i + 1));

    // i番目はB（2）に使う
    // p.pop_back();
    // p.push_back(2);
    p[i] = 2;
    ret = min(ret, dfs(i + 1));

    // i番目は最後まで使わない
    // p.pop_back();
    // p.push_back(3);
    p[i] = 3;
    ret = min(ret, dfs(i + 1));

    return ret;
}

int main() {
    cin >> N >> A[0] >> A[1] >> A[2];
    l.resize(N);
    rep(i, N) cin >> l[i];

    p.resize(N);
    cout << dfs(0) << endl;
    return 0;
}