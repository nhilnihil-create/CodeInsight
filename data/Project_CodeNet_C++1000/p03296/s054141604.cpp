#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    vector<int> a(N);
    rep(i, N) cin >> a[i];

    int ans = 0;
    rep(i, N - 1) {
        if (a[i] == a[i + 1]) {
            ans++;
            i++;
        }
    }

    cout << ans << endl;
}