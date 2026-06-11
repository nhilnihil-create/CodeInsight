#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    rep(i, n) {
        vector<bool> f1(26);
        vector<bool> f2(26);
        vector<bool> f3(26);
        rep(j, n) {
            if (j<=i) {
                f1[s[j]-'a'] = true;
            }
            else {
                f2[s[j]-'a'] = true;
            }
        }
        int res = 0;
        rep(j, 26) {
            f3[j] = f1[j] & f2[j];
            if (f3[j]) res++;
        }
        ans = max(ans, res);
    }
    
    cout << ans << endl;
    return 0;
}
