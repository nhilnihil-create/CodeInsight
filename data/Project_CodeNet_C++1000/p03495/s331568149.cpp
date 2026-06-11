#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
    int N; cin >> N;
    int K; cin >> K;

    int A[N];
    rep(i, N) A[i] = 0; // 初期化
    rep(i, N) {
        int a; cin >> a;
        A[a - 1]++;
    }

    // 降順に並び替え
    sort(A, A + N, greater<int>());
    
    // 書き換える必要のないボールの最大値
    int sum = 0;
    rep(i, K) {
        sum += A[i];
    }

    // 少なくとも書き換える必要のある個数
    int ans = N - sum;
    cout << ans << endl;
    return 0;
}
