#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

typedef long long ll;
typedef pair<int, int> Pi;

const int MAX = 1e6 + 5;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end(), greater<int>());

    map<int, int> cnt;
    rep(i, N) cnt[A[i]]++;

    int ans = 0;
    rep(i, N) {
        if (cnt[A[i]] <= 0) continue;
        cnt[A[i]]--;
        int num = 1;
        while (num <= A[i]) num <<= 1;
        if (0 < cnt[num - A[i]]) {
            ans++;
            cnt[num - A[i]]--;
        }
    }

    cout << ans << endl;
}