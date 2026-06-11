//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    vi b(n);
    rep(i, n) {
        cin >> b[i];
    }
    bool x = true;

    vi ans(n);
    rep(i, n) {
        for(int j=n-i-1; j>=0; --j) {
            if(b[j] == j + 1) {
                ans[n-i-1] = j+1;
                b.erase(b.begin()+j);
                break;
            }
            if(j == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    rep(i, n) {
        cout << ans[i] << '\n';
    }
}