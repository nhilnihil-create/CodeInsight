#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n, m, p[12];
    vector<int> x[12];

    cin >> n >> m;
    rep(i, m) {
        int k, a;
        cin >> k;
        rep(j, k) {
            cin >> a;
            a--;
            x[i].push_back(a);
        }
    }
    rep(i, m) cin >> p[i];

    int cou = 0;
    for(int i = 0; i < (1 << n); i++) {
        int bit[12]; 
        for(int j = 0; j < n; j++) bit[j] = (i / (1 << j)) % 2;
        int ans = 0;
        for(int j = 0; j < m; j++)  {
            int ret = 0;
            for(int v : x[j]) ret ^= bit[v];
            if(ret != p[j]) ans++;
        }
        if (ans == 0) cou++;
    }

    cout << cou << endl;

    return 0;
}