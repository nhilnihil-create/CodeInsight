#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    vector<vector<int>> s(m, vector<int>(n+1));
    vector<int> k(m);
    vector<int> p(m);
    REP(i, m) {
        cin>>k[i];
        REP(j, k[i]) {
            cin>>s[i][j];
        }
    }
    REP(i, m) cin>>p[i];
    int ans = 0;
    bool ok;
    int mod2;

    for (int bit = 0; bit < (1 << n); ++bit) {
        ok = true;
        REP(i, m) {  // 電球
            mod2 = 0;
            // (i>>(v[j][l]-1) & 1
            REP(j, k[i]) { //　ついてるかを見極める
                if (bit & 1<<(s[i][j]-1)) mod2 += 1;
                // cout << "turn on light: " << bitset<5>(bit) << " ";
                // cout << s[i][j] << " " << (1 << (s[i][j]-1)) << " " << (bit & 1<<(s[i][j]-1)) << endl;
            }
            if(mod2 % 2 != p[i]) ok = false;
        }
        if(ok){
            // cout << bit << endl;
            ans += 1;
        }
    }
    cout << ans;

    return 0;
}