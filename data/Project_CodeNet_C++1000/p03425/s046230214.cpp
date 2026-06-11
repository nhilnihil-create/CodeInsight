#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    ll ans = 0;
    string march = "MARCH";
    vector<int> num(5);
    rep(i, n) {
        rep(j, 5) {
            if (s[i][0]==march[j]) num[j]++;
        }
    }


    for (int i=0; i<=2; i++) {
        for (int j=i+1; j<=3; j++) {
            for (int k=j+1; k<=4; k++) {
                ans += (ll)num[i]*num[j]*num[k];
            }
        }
    }

    
    cout << ans << endl;
    return 0;
}
