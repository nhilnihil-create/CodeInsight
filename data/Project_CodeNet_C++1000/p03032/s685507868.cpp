//解説見た
#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    int n,k; cin >> n >> k;
    int v[50];
    rep(i,n) cin >> v[i];
    int ans = 0;
    rep(a, min(n,k)+1) {
        rep(b, min(n,k)-a+1) {
            int va = 0;
            vector<int> stone;
            for (int i=0; i<a; i++) {
                stone.push_back(v[i]);
                va += v[i];
            }
            for (int i=n-1; i>n-b-1; i--) {
                stone.push_back(v[i]);
                va += v[i];
            }
            sort(stone.begin(), stone.end());
            int s = stone.size();
            rep(i, min(k-(a+b), s ) ) {
                if (stone[i] >= 0) break;
                va -= stone[i];
            }
            ans = max(ans,va);
        }
    }
    cout << ans << endl;
}