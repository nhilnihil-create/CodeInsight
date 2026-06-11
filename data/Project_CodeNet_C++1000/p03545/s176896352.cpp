#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    string s;
    cin >> s;
    vector<int> a(4);
    rep(i, 4) a[i] = s[i] - '0';
    int ans = 0;
    rep(i, 1<<3) {
        int now = a[0];
        rep(j, 3) {
            if (i>>j&1) now += a[j+1];
            else now -= a[j+1];
        }
        if (now==7) {
            ans = i;
            break;
        }
    }
    rep(i, 4) {
        cout << a[i];
        if (i<3) {
            if (ans>>i&1) cout << '+';
            else cout << '-';
        }
    }
    cout << "=7" << endl;
    return 0;
}
