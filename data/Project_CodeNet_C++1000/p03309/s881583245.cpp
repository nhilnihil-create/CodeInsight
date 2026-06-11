#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define int long long

signed main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n){
        int t; cin >> t;
        a[i] = t - (i + 1);
    }
    
    sort(ALL(a));
    int median;
    if(n % 2 == 1){
        median = a[n/2];
    }else{
        median = (a[n/2-1] + a[n/2])/2;
    }
    
    int ans = 1e16; //INF
    reps(b, median-5, median+5){
        int t = 0;
        rep(i,n){
            t += abs(a[i] - b);
        }
        ans = min(ans, t);
    }
    
    cout << ans << endl;
}