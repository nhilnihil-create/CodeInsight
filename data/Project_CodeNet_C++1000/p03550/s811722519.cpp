#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, Z, W; cin >> N >> Z >> W;
    vector<int> a(N);
    rep(i, N){
        cin >> a[i];
    }

    if(N == 1){
        cout << abs(a[0] - W) << endl;
        return 0;
    }
    int ans = max(abs(a[N-1] - W), abs(a[N-2] - a[N-1]));
    cout << ans << endl;

    return 0;
}