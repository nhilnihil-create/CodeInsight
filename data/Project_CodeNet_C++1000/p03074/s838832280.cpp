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
    int n, k;
    string s;
    cin >> n >> k >> s;

    int cou = 0;
    vi cc(1, 0);
    rep(i, n-1) {
        if(s[i] != s[i+1]) {
            cou++;
            cc.push_back(i+1);
        }
    }
    cc.push_back(n);

    if(cou <= 2*k-1) {
        cout << n << endl;
        return 0;
    }
    if(cou == 2*k && s[0] == 1) {
        cout << n << endl;
        return 0;
    }


    int ans = 0;
    
    if(s[0] == '1') {
        int i = 0;
        while(1) {
            if(i + 2 * k + 1 >= cc.size()) break;
            ans = max(ans, cc[i+2*k+1] - cc[i]);
            i += 2;
        }
        ans = max(ans, n - cc[i]);
    } else {
        int i = 1;
        while(1) {
            if(i + 2 * k + 1 >= cc.size()) break;
            ans = max(ans, cc[i+2*k+1] - cc[i]);
            i += 2;
        }
        ans = max(ans, n - cc[i]);
        ans = max(ans, cc[2*k]);
    }

    cout << ans << endl;
}