#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> h(N);
    int ans = 0;
    rep(i, N){
        cin >> h[i];
        if(i == 0){
            ans += h[i];
        } else {
            if(h[i] <= h[i-1]){
                continue;
            } else {
                ans += h[i] - h[i-1];
            }
        }
    }

    cout << ans << endl;

    return 0;
}