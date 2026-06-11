#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<typename T> using rev_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class S, class T> void map_init(map<S, T> &m, S k, T v){if(!m.count(k)) m[k] = v;}
void R_YESNO(bool p) { cout << (p ? "YES" : "NO") << endl; }
void R_YesNo(bool p) { cout << (p ? "Yes" : "No") << endl; }
int main() {
    i64 N, K;
    cin >> N >> K;
    i64 ans = 0;
    if(!K) {
        cout << N * N << endl;
        return 0;
    }
    for(int b = K + 1; b <= N; b++) {
        ans += (N / b) * (b - K);
        ans += max<i64>(0, (N % b) - K + 1);
    }
    cout << ans << endl;
    return 0;
}