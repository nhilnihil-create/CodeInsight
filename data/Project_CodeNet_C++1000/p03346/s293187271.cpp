#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, ans=1, tmp=1;
/*
int LIS(const vector<long long> &a) {
    int N = (int)a.size();
    vector<long long> dp(N, INF);
    for (int i = 0; i < N; ++i) {
        // dp[k] >= a[i] となる最小のイテレータを見つける
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);

        // そこを a[i] で書き換える
        *it = a[i];
    }

    // dp[k] < INF となる最大の k に対して k+1 が答え
    // それは dp[k] >= INF となる最小の k に一致する
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}
*/
signed main() {
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        ll a;
        cin >> a;
        a--;
        A[a] = i;
    }
    for(int i=1;i<N;i++) {
        if(A[i-1]<A[i]) {
            tmp++;
        }
        else {
            tmp = 1;
        }
        ans = max(ans,tmp);
    }
    cout << N-ans << endl;
}   