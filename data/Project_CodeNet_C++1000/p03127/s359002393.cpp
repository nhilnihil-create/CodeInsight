#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> A;
int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());

    ll current = A[0];
    ll idx = 0;

    while (true) {
        bool amari = false;
        ll tmp_ans = current; 
        // cout << "idx: " << idx << " current: " << current << endl;
        for (int i = 0; i < N; i++) {
            // if (idx == i) {
            //     cout << "hoge" << endl;
            //     continue;
            // }
            if (A[i] == current) continue;
            A[i] = A[i] % current;

            if (A[i] > 0 && A[i] < tmp_ans) {
                tmp_ans = A[i];
                amari = true;
                idx = i;
            } 
        }
        // cout << endl;
        current = tmp_ans;

        // rep(j, N) cout << A[j] << " ";
        // cout << endl;

        if (amari == false) {
            cout << current << endl;
            return 0;
        } 
    }

}