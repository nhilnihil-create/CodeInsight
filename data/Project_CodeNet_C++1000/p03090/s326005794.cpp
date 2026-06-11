#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    int N; cin >> N;

    int nb_ans = 0;
    vector<P> ans;
    int TN = N;
    if (N%2 == 1) {
        TN -= 1;
    }
    rep(i, N-1) {
        repr(j, i+1, N) {
            if (i + j + 2 == TN +1) continue;
            ans.emplace_back(i, j);
        }
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i].first + 1 << " " << ans[i].second +1 << endl;
    }
    return 0;
}