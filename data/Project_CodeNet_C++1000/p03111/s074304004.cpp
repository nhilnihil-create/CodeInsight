#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e7;
int N;
int A, B, C;
int l[8];

int dfs(int cur_n, int a, int b, int c) {
    if (cur_n == N) {
        // 全ての探索を終わった
        if (a == 0 || b == 0 || c == 0) {
            return INF;
        } else {
            return abs(A-a) + abs(B-b) + abs(C-c) - 30;
        }
    }
    int res1, res2, res3, res4;
    res1 = dfs(cur_n+1, a, b, c); // a, b, cに足さない
    // +10は合成魔法分 何もないところから足された+10分は最後に辻褄合わせ
    res2 = dfs(cur_n+1, a+l[cur_n], b, c) + 10;
    res3 = dfs(cur_n+1, a, b+l[cur_n], c) + 10;
    res4 = dfs(cur_n+1, a, b, c+l[cur_n]) + 10;
    return min({res1, res2, res3, res4});
}

int main() {
    cout << fixed << setprecision(10);
    
    // int N, A, B, C; 
    cin >> N >> A >> B >> C;
    // vector<int> l(N);
    rep(i, N) cin >> l[i];
    cout << dfs(0, 0, 0, 0) << endl;
    return 0;
}