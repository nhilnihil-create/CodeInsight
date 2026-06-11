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
    cin  >> n;
    string s;
    cin >> s;
    int num = 0;
    rep(i, n) {
        if(s[i] == '#') {
            num = i;
            break;
        }
    }
    s = s.substr(num);
    n = s.size();
    vi sumd(n+1), sums(n+1);
    rep(i, n) {
        if(s[i] == '.') {
            sumd[0]++;
        }
    }
    rep(i, n) {
        sumd[i+1] = sumd[i];
        sums[i+1] = sums[i];
        if(s[i] == '.') {
            sumd[i+1]--;
        } else {
            sums[i+1]++;
        }
    }
    
    int ans = 100000000;
    rep(i, n+1) {
        ans = min(ans, sumd[i]+sums[i]);
    }

    cout << ans << endl;
}