#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;

vector<P> ken[100005];

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int p, y;
        cin >> p >> y;
        ken[p].emplace_back(y, i);
    }
    vector<string> ans(m);
    rep(i, n+1) {
        if (ken[i].size()==0) continue;
        sort(ken[i].begin(), ken[i].end());
        int x = 0;
        for (P p: ken[i]) {
            int id = p.second;
            int year = p.first;
            int now = i;
            string s = "";
            int z = 100000;
            while (z) {
                s += ('0' + now/z);
                now %= z;
                z /= 10;
            }
            x++;
            int nowx = x;
            z = 100000;
            while(z) {
                s += ('0' + nowx/z);
                nowx %= z;
                z /= 10;
            }
            ans[id] = s;
        }
    }
    
    
    
    rep(i, m) {
        cout << ans[i] << endl;
    }
    return 0;
}
