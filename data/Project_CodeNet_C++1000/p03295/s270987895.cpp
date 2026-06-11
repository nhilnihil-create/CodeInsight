#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N, M;
vector<int> A, B;

set<P> s;
multiset<int> w;


void input() {
    cin >> N >> M;
    A = B = vector<int>(M);
    rep(i, M) cin >> A[i] >> B[i];
}


int main() {
    input();
    rep(i, M) {
        s.insert(P(A[i], B[i]));
        w.insert(B[i]);
    }
    int ans = 0;
    while (!w.empty()) {
        ans++;
        int v = *w.begin();
        auto x = s.upper_bound(P(v, 0));
        auto itr = s.begin();
        while (itr != x) {
            w.erase(w.find(itr->second));
            s.erase(itr++);
        }
    }
    cout << ans << endl;
}
