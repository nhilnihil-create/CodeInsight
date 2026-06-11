#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int cur = A[0]; int cnt = 1; int sum = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] == cur) {
            cnt++;
        } else {
            if (cur < cnt) {
                sum += cnt - cur;
            } else if (cur > cnt){
                sum += cnt;
            }
            cur = A[i];
            cnt = 1;
        }
    }
    if (cur < cnt) {
        sum += cnt - cur;
    } else if (cur > cnt) {
        sum += cnt;
    }

    cout << sum << endl;
    return 0;
}