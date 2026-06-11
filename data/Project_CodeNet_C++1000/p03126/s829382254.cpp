#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
const ll mod = 1000000007;


int main(){
    int n, m;
    cin >> n >> m;

    int ans = (1<<m)-1;
    vector<int> v(n);
    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            a--;
            v[i] |= 1<<a; 
        }
    }
    
    rep(i, n) {
        ans &= v[i];
    }
    
    int num = __builtin_popcount(ans);
    cout << num << endl;
    return 0;
}
