#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

vector<pair<int,int>> vp;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    bool flag = 1;
    if (s[0] == '0' || s[n-1] == '1') flag = 0;
    rep(i, n-1){
        if (s[i] != s[n-i-2]) flag = 0;
    }

    if (!flag){
        cout << -1 << endl;
        return 0;
    }
    int p = n;
    rrep(i, n-1){
        if (s[i] == '1') {
            vp.push_back({p, i+1});
            p = i+1;
        }
        else vp.push_back({p, i+1});
    }

    for(auto e : vp) cout << e.first << " " << e.second << endl;

    return 0;
}
