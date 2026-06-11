#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ull, int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ull> A(N);
    vector<P> V(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> V[i].second >> V[i].first;
    sort(A.begin(), A.end());
    sort(V.begin(), V.end());
    int now = M - 1;          //現在位置
    int time = V[now].second; //使用回数

    for(int i = 0; i < N; i++) {
        // cout << A[i] << " ";
        if(V[now].first > A[i]) {
            A[i] = V[now].first;
            time--;
        }
        if(time == 0) {
            now--; //現在位置更新
            if(now < 0) {
                break;
            }
            time = V[now].second;
        }
    }
    ull sum = 0;
    rep(i, N) {
        // cout << A[i] << " " << endl;
        sum += A[i];
    }
    cout << sum << endl;
    return 0;
}
