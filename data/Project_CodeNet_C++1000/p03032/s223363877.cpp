#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> d(N);
    for (int i = 0; i < N; i++) cin >> d[i];

    int ans = -INF;
    for (int i = 0; i <= min(K, N); i++) {
        for (int j = 0; j <= min(K, N); j++) {
            if (i + j > min(N, K)) continue;
            vector<int> v;
            copy(d.begin(), d.begin() + i, back_inserter(v));
            copy(d.rbegin(), d.rbegin() + j, back_inserter(v));
            sort(v.begin(), v.end());
            int tmp = accumulate(v.begin(), v.end(), 0);
            for (int k = 0; k < min((int)v.size(), K - (i+j)); k++) if (v[k] < 0) tmp -= v[k];
            ans = max(ans, tmp);
        }
    }
    cout << ans << '\n';
}
