#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long mod = 1e9+7;
long long power(long long a, long long b, long long m = mod) {
    if(b < 0) {
        return power(power(a, -b), mod-2);
    }
    long long x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
const int N = 2e5+9;
vector<int> g[N][2];
int d[N];
signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int k; cin >> k;
    for(int i = 1; i < k; i++) {
        g[i][1].push_back((i+1)%k);
        g[i][0].push_back(i*10ll%k);
    }
    deque<int> dq({1});
    memset(d, 0x3f, sizeof d);
    d[1] = 1;
    while(!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for(int v: g[u][0]) {
            if(d[v] > d[u]) {
                d[v] = d[u];
                dq.push_front(v);
            }
        }
        for(int v: g[u][1]) {
            if(d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                dq.push_back(v);
            }
        }
    }
    cout << d[0] << endl;








    return 0;
    
}