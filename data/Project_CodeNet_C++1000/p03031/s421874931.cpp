#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int>k(m);
    vector<vector<int>>s(m);
    rep(i,m){
        cin >> k[i];
        s[i].assign(k[i],0);
        rep(j,k[i]){
            cin >> s[i][j];
            s[i][j]--;
            }

    }
    vector<int>p(m);
    rep(i,m)cin >> p[i];
    int ans = 0;
    for(int i = 0;i < 1<<n;i++){
        bool ok = true;
        rep(j,m){
            int cnt = 0;
            rep(l,k[j]){
                if(i >> s[j][l] & 1)cnt++;
            }
            if(cnt % 2 != p[j])ok = false;
            //cout << i << " " << j << " " << cnt << endl;
        }
        if(ok)ans++;
    }
    
    cout << ans << endl;
    return 0;
}