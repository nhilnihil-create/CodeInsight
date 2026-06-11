#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) (1 + (int)((a) - 1)/(int)(b))
//#define int long long

signed main(){
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    
    int ans = 0;
    reps(x,0,k)reps(y,0,k-x){
        int z = k - x - y;
        ans = max(ans, a*(1<<x) + b*(1<<y) + c*(1<<z));
    }
    
    cout << ans << endl;
}