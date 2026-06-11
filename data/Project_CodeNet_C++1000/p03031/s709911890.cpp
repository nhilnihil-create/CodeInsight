// C - Switches
#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s;
    vector<int> p(m);
    s.resize(m);
    int k;
    rep(i, m){
        cin >> k;
        s[i].resize(k);
        rep(j, k){
            cin >> s[i][j];
            s[i][j] -= 1;
        }
    }
    rep(i, m) cin >> p[i];
    int ans = 0;
    
    for(int bit=0; bit<(1<<n); bit++){
        bool flag = true;
        rep(i, m){
            int cnt = 0;
            for(auto e : s[i]){
                if(bit&(1<<e)) cnt++;
            }
            if(cnt%2 != p[i]) flag=false;
        }
        if(flag) ans++;
    }
    cout << ans << endl;
    return 0;
}