#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define all(a) a.begin(), a.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e15;

int d[100010];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int k = -1;
    for(int i = 1; i * i <= 2 * n; i++){
        if(i * (i + 1) == 2 * n){
            k = i + 1; break;
        }
    }
    if(k == -1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << k << endl;
    int now = 1;
    vector<vector<int> > ans(k, vector<int>());
    rep(i, 0, k){
        rep(j, 0, i){
            ans[i].push_back(d[j]);
            d[j]++;
        }
        d[i] = now;
        rep(j, 0, k - 1 - i){
            ans[i].push_back(now);
            now++;
        }
    }
    rep(i, 0, ans.size()){
        cout << k - 1 << " ";
        for(int ii = 0; ii < ans[i].size(); ii++){
            if(ii) cout << ' ';
            cout << ans[i][ii];
        }
        cout << endl;
    }
}