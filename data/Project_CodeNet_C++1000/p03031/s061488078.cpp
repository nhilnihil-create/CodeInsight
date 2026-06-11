#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n, m; cin >> n >> m;
    V<V<int> > v(m);
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int s; cin >> s;
            s--;
            v[i].push_back(s);
        }
    }
    V<int> w(m);
    for(int i = 0; i < m; i++) cin >> w[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        bool flag = true;
        for(int j = 0; j < m; j++){
            int cnt = 0;
            for(int k = 0; k < (int)v[j].size(); k++){
                if(bit & (1 << v[j][k])) cnt++;
            }
            if(cnt % 2 != w[j]){
                flag = false;
            }
        }
        if(flag) ans++;
    }
    cout << ans << endl;

    return 0;
}
