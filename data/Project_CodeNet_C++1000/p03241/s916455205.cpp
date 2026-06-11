#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;


int main(){
    int n, m;
    cin >> n >> m;
    int ans;
    vector<int> fac;
    for (int i=1; i*i<=m; i++) {
        if (m%i==0) {
            fac.push_back(i);
            if (i*i!=m) {
                fac.push_back(m/i);
            }
        }
    }
    sort(fac.begin(), fac.end());
    auto it = upper_bound(fac.begin(), fac.end(), m/n);
    it--;
    ans = *it;
    
    
    cout << ans << endl;
    return 0;
}
