#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    int N, K, Q;
    cin >> N >> K >> Q;
    Vl A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll ans = L_INF;
    Vl cand, part;
    for (int i = 0; i < N; i++) {
        cand.clear();
        part.clear();
        int n_part;
        for (int j = 0; j < N; j++) {
            if (A[i] <= A[j]) {
                part.emplace_back(A[j]);
            }
            else {
                n_part = (int)part.size();
                if (n_part >= K) {
                    sort(part.begin(), part.end());
                    cand.insert(cand.end(), part.begin(), part.begin() + (n_part - K) + 1);
                }
                part.clear();
            }
        }

        n_part = (int)part.size();
        if (n_part >= K) {
            sort(part.begin(), part.end());
            cand.insert(cand.end(), part.begin(), part.begin() + (n_part - K) + 1);
        }
        part.clear();


        if ((int)cand.size() >= Q) {
            sort(cand.begin(), cand.end());
            ans = min(ans, cand[Q - 1] - cand[0]);
        }
    }

    cout << ans << endl;

    return 0;
}