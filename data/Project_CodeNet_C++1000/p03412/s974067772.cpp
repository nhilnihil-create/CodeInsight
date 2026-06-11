#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

#define int long long
typedef pair<int, int> P;

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*
#define cin ifs
#define cout ofs
ifstream ifs("in.txt");
ofstream ofs("out.txt");
//*/

int N;
int a[220000], b[220000];
int b_mod[30][220000];

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];
    for (int i = 0; i < 30; i++) {
        int mod = 1 << (i + 1);
        for (int j = 0; j < N; j++) b_mod[i][j] = b[j] % mod;
        sort(b_mod[i], b_mod[i] + N);
    }
    int ans = 0;
    for (int i = 0; i < 30; i++) {
        int cur = 0;
        int T = 1 << i;
        for (int j = 0; j < N; j++) {
            int A = a[j] % (T << 1);
            cur += lower_bound(b_mod[i], b_mod[i] + N, 2 * T - A) - lower_bound(b_mod[i], b_mod[i] + N, 1 * T - A);
            cur += lower_bound(b_mod[i], b_mod[i] + N, 4 * T - A) - lower_bound(b_mod[i], b_mod[i] + N, 3 * T - A);
        }
        ans += (cur % 2) << i;
    }
    cout << ans << endl;
    return 0;
}