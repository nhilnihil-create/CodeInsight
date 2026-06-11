#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    rep(i, N) {
        int a;
        cin >> a;
        A[i] = {a, i + 1};
    }
    
    vector<int> ans;
    while (A.size()) {
        int k = -1;
        for (int i = A.size() - 1; i >= 0; --i) {
            if (A[i].first == A[i].second) {
                k = i;
                break;
            }
        }
        if (k == -1) {
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(A[k].first);
        A.erase(A.begin() + k);
        rep(i, A.size()) A[i].second = i + 1;
    }
    reverse(ans.begin(), ans.end());
    rep(i, N) cout << ans[i] << endl;
    return 0;
}
