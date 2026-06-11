//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 3) {
        cout << 2 << ' ' << 5 << ' ' << 63 << endl;
        return 0;
    }
    int sum = 0;
    vi ans(n);
    int six[] = {2, 3, 4, 6};
    int x = 0;
    rep(i, n/4) {
        rep(j, 4) {
            int num = six[j] + i*6;
            ans[i*4+j] = num;
            sum += num;
            sum %= 6;
            x = num;
        }
    }

    if(!(n%4)) {
        if(sum) {
            ans[n-1] += 3;
        }
    } else {
        switch(n%4) {
            case 1:
                if(sum) {
                    ans[n-1] = x+3;
                } else {
                    ans[n-1] = x+6;
                }
                break;
            case 2:
                if(sum) {
                    ans[n-2] = x+3;
                    ans[n-1] = x+6;
                } else {
                    ans[n-2] = x+2;
                    ans[n-1] = x+4;
                }
                break;
            case 3:
                if(sum) {
                    ans[n-1] = x+2;
                    ans[n-2] = x+3;
                    ans[n-3] = x+4;
                } else {
                    ans[n-1] = x+2;
                    ans[n-2] = x+4;
                    ans[n-3] = x+6;
                }
                break;
        }
    }

    rep(i, n) {
        cout << ans[i] << (i == n-1?'\n':' ');
    }
}