#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int N, K; cin >> N >> K;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        m[x]++;
    }

    vector<int> A;
    for (auto p: m) {
        A.push_back(p.second);
    }

    int all = A.size();
    int sum = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < all - K; i++) {
        sum += A[i];
    }

    cout << sum << endl;
    return 0;
}