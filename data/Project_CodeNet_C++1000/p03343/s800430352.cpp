#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = numeric_limits<int>::max();
    for (int i = 0; i < N; i++) {
        int mi = A[i];
        

        priority_queue<int, vector<int>, greater<int>> Que;

        int pre_j = -1;
        for (int j = 0; j < N; j++) {
            if (A[j] < mi) {
                if (j - pre_j != 1) {
                    int l = j - pre_j - 1;
                    priority_queue<int, vector<int>, greater<int>> temp;
                    for(int k = pre_j + 1; k < j; k++) {
                        temp.push(A[k]);
                    }
                    for (int k = 0; k < l - K + 1; k++) {
                        Que.push(temp.top()); temp.pop();
                    }
                }
                pre_j = j;
            }
        }
        if (N - pre_j != 1) {
            int l = N - pre_j - 1;
            priority_queue<int, vector<int>, greater<int>> temp;
            for(int k = pre_j + 1; k < N; k++) {
                temp.push(A[k]);
            }
            for (int k = 0; k < l - K + 1; k++) {
                Que.push(temp.top()); temp.pop();
            }
        }

        if (Que.size() < Q) continue;
        if (Que.top() != mi) continue;
        for (int i = 0; i < Q - 1; i++) {
            Que.pop();
        }
        int ma = Que.top(); Que.pop();
        ans = min(ans, ma - mi);
    }
    cout << ans << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}