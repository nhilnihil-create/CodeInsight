#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    rep(i, 2) {
        rep(j, n) {
            if(i) cin >> b[j];
            else cin >> a[j];
        }
    }
    int ans = 0;
    rep(i, n) {
        int cou = 0;
        rep(j, i+1) {
            cou += a[j];
        }
        for (int j = i; j < n; j++) {
            cou += b[j];
        }
        ans = max(ans, cou);
    }

    cout << ans << endl;

    return 0;
}