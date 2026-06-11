#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N;
    string A, B, C;
    cin >> N >> A >> B >> C;

    int ans = 0;
    rep(i, N) {
        if (A[i] != B[i] && A[i] != C[i] && B[i] != C[i]) {
            ans += 2;
        } else if (A[i] != B[i] || A[i] != C[i] || B[i] != C[i]) {
            ans++;
        }
    }

    cout << ans << endl;
}