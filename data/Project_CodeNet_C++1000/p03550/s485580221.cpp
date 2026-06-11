#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 2005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N, Z, W;
    cin >> N >> Z >> W;

    vector<int> a(N);
    rep(i, N) cin >> a[i];

    if (N == 1) {
        cout << abs(a[0] - W) << endl;
    } else {
        cout << max(abs(W - a[N-1]), abs(a[N-2] - a[N-1])) << endl;
    }
}