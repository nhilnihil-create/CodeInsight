#include <bits/stdc++.h>
using namespace std;
 
//#define int long long
const int MOD = 1e9 + 7;
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((ll)((a) + (b) - 1)/(ll)(b))

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n+2);
    v[0] = v[n+1] = 0;
    rep(i,n) cin >> v[i+1];
    
    int ans = 0;
    reps(left,0,n)reps(right,left+1,n+1){
        const int JEWELS = left + n+1-right;
        if(JEWELS > k) continue;
        
        priority_queue<int, vector<int>, greater<>> q;
        int value = 0;
        
        for(int i = 0; i <= left; i++){
            value += v[i];
            q.push(v[i]);
        }
        for(int i = n+1; i >= right; i--){
            value += v[i];
            q.push(v[i]);
        }
        
        rep(i,k-JEWELS){
            if(q.empty()) break;
            if(q.top() >= 0) break;
            value -= q.top();
            q.pop();
        }
        
        ans = max(ans, value);
    }
    
    cout << ans << endl;
}