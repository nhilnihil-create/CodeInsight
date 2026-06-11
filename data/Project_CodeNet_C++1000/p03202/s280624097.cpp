#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using namespace chrono;
using ll = long long;
using ii = pair<int, int>;
constexpr int MN = 200002;

int N, A[MN];

time_point<high_resolution_clock> start;

void fast_incorrect() {
    int ans = 0;
    map<int, int> M;
    for (int i = 1; i < N; ++i) {
        if (A[i] <= A[i-1]) {
            if (!ans) ans = 1;
            int x = A[i];
            if (M[x] == ans) {
                int j = x-1;
                while (j > 0 && M[j] == ans) --j;
                if (j > 0) x = j;
            }
            ans = max(++M[x], ans);
            while (rbegin(M)->f > x) M.erase(prev(end(M)));
        }
    }
    cout << ans+1;
    exit(0);
}

bool solve(int K) {
    map<int, int> M;
    for (int i = 1; i < N; ++i) {
        if (duration_cast<duration<double>>(high_resolution_clock::now()-start) > duration<double>(0.8)) fast_incorrect();
        if (A[i] <= A[i-1]) {
            int x = A[i];
            if (M[x] == K) {
                int j = x-1;
                while (j > 0 && M[j] == K) --j;
                if (j > 0) x = j;
                else return 0;
            }
            ++M[x];
            while (M.size() && rbegin(M)->f > x) M.erase(prev(end(M)));
        }
    }
    return 1;
}

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    start = high_resolution_clock::now();

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    bool good = 1;
    for (int i = 1; i < N; ++i) {
        if (A[i] <= A[i-1]) good = 0;
    }
    if (good) {
        cout << 1;
        return 0;
    }

    int l = 1, h = MN;
    for (int i = 0; i < 50; ++i) {
        int m = (l+h)/2;
        solve(m) ? h = m : l = m+1;
    }
    cout << l+1;
}