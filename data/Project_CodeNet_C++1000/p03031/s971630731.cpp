#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> v;v.assign(m,vector<int>());
    for(int i = 0;i < m;i++){
        int x; cin >> x;
        for(int j = 0;j < x;j++){
            int y; cin >> y;y--;
            v[i].push_back(y);
        }
    }
    vector<int> p;
    for(int i = 0;i < m;i++){
        int x; cin >> x;p.push_back(x);
    }
    
    int e = 0;
    
    for (int bit = 0; bit < (1<<n); bit++){
        vector<bool> S(n);
        for (int i = 0; i < n; i++) {
            if (bit & (1<<i)) {
                S[i] = true;
            }
        }
        int sum = 0;
        for(int j = 0;j < m;j++){
            int cnt = 0;
            for(int k = 0;k < v[j].size();k++){
                if(S[v[j][k]]) cnt++;
            }
            if(cnt % 2 == p[j]) sum++;
        }
        if(sum == m) e++;
    }
    cout << e;
}
