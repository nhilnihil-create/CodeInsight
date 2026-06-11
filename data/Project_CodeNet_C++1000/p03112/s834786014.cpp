#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>

using namespace std;

#define rep(i, n) for(long int i = 0; i < n; i++)

int main(){
    long int a, b, q;
    cin >> a >> b >> q;
    long int s[a];
    rep(i, a) cin >> s[i];
    long int t[b];
    rep(i, b) cin >> t[i];
    sort(s, s + a);
    sort(t, t + b);
    long int x1[q];
    rep(i, q) cin >> x1[i];
    rep(i, q) {
        long int x = x1[i];
        long int idx1 = lower_bound(s, s + a, x) - s;
        long int idx3 = lower_bound(t, t + b, x) - t;
        long int ans;
        ans = 10000000000000000;
        if (idx1 < a && idx3 < b){
            ans = min(ans, max(s[idx1] - x, t[idx3] - x));
        }
        if (idx1 > 0 && idx3 > 0){
            ans = min(ans, max(x - s[idx1-1], x - t[idx3-1]));
        }
        if (idx1 < a && idx3 > 0){
            ans = min(ans, min(s[idx1] - x, x - t[idx3-1]) * 2 + max(s[idx1] - x, x - t[idx3-1]));
        }
        if(idx1 > 0 && idx3 < b){
            ans = min(ans, min(x - s[idx1-1], t[idx3] - x) * 2 + max(x - s[idx1-1], t[idx3] - x)); 
        }
        cout << ans << endl;
    } 
}
