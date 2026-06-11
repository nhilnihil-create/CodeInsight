#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define int long long

signed main(){
    int n, k;
    cin >> n >> k;
    int ans = pow(n/k, 3);
    if(k % 2 == 0){
        ans += pow(n/k + (n % k >= k/2 ? 1 : 0), 3);
    }
    cout << ans << endl;
}