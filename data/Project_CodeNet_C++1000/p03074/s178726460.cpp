#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> r;
    r.push_back(0);
    for(int i = 1; i < n; i++){
        if (s[i] != s[i-1]) r.push_back(i);
    }

    // rep(i, r.size()) cout << r[i] << endl;
    int ans = 0;
    int m = r.size();
    // rep(i, m) cout << r[i] << " ";
    // cout << endl;
    rep(i, r.size()){
        int tmp, cnt;
        if (s[r[i]] == '0'){
            if (2 * k + i > m - 1) tmp = n;
            else tmp = r[2 * k + i];
            cnt = tmp - r[i];
            // cout << cnt << endl;
        }
        else {
            if (2 * k + i + 1 > m - 1) tmp = n;
            else tmp = r[2 * k + i + 1];
            cnt = tmp - r[i];
            // cout << cnt << endl;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}