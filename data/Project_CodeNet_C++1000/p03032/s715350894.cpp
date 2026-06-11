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
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    int ans = 0;
    int times = min(N, K);
    for (int t = 1; t <= times; t++) {
        for (int l = 0; l <= t; l++) {
            int r = t - l;
            vector<int> onHand;
            onHand.insert(onHand.end(), a.begin(), a.begin() + l);
            onHand.insert(onHand.end(), a.rbegin(), a.rbegin() + r);
            sort(onHand.begin(), onHand.end());
            int remainingTimes = min(K - t, t);
            int sum = accumulate(onHand.begin(), onHand.end(), 0);
            for (int i = 0; i < remainingTimes; i++) {
                if (onHand[i] < 0) sum -= onHand[i];
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';
}
