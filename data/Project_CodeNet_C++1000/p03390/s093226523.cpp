#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    rep(i, 0, n){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        int ans = 0;
        if(a == b){
            ans = 2 * a - 2;
        }else if(a + 1 == b){
            ans = 2 * a - 2;
        }else{
            int tmp = a * b;
            int sqt = sqrt(tmp);
            if(sqt * sqt == tmp) sqt--;
            ans = 2 * sqt - 1;
            if(sqt * (sqt + 1) >= tmp) ans -= 1;
        }
        cout << ans << endl;
    }
}