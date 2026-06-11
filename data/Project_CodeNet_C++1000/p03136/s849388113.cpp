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


int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    sort(l.begin(), l.end());
    int sum = 0;
    rep(i, n-1) {
        sum += l[i];
    }
    string ans = "Yes";
    if (l[n-1]>=sum) {
        ans = "No";
    }
    
    
    
    
    cout << ans << endl;
    return 0;
}
