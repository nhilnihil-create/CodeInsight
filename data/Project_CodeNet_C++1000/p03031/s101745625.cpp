#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> s(m);
    for(int i = 0; i < m; i++) {
        cin >> k[i];
        s[i].resize(k[i]);
        for(int j = 0; j < k[i]; j++){
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    vector<int> p(m);
    for(int i = 0; i < m; i++) cin >> p[i];
    ll ans = 0;
    for(int bit = 0; bit < (1<<n); bit++) {
        bool f = true;
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < k[i]; j++) {
                if(bit & (1<<s[i][j])) cnt++;
            }
            if(cnt % 2 != p[i]) f = false; 
        }
        if(f) ans++;
    }
    cout << ans << endl;
    return 0;
}