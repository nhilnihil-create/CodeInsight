#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> k(m);
    vector<vector<int>> s(m);
    vector<int> p(n);
    
    rep(i, m){
        cin >> k[i];
        s[i].resize(k[i]);
        rep(j, k[i]){
            cin >> s[i][j];
            s[i][j];
        }
    }
    rep(i, m)cin >> p[i];
    
    
    int ans = 0;
    rep(i, 1<<n){
        int cnt1 = 0;
        rep(j, m){
            int cnt2 = 0;
            rep(l, k[j]){
                if(i & 1<<(s[j][l]-1))cnt2++;
            }
            if(cnt2%2==p[j])cnt1++;
        }
        if(cnt1==m)ans++;
    }
    
    cout << ans << endl;
}