#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;

int main(){
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    lint a[n];
    rep(i, n) scanf("%lld", &a[i]);
    lint ans = 1e18;
    rep(i, n){
        int l = 0;
        int r = 0;
        vector<lint> t;
        while(l < n){
            vector<lint> v;
            while(r < n && a[r] >= a[i]){
                v.push_back(a[r]);
                ++r;
            }
            l = r+1;
            r = l;
            if(v.size() < k) continue;
            sort(v.begin(), v.end());
            rep(j, v.size()-k+1) t.push_back(v[j]);
        }
        if(t.size() < q) continue;
        sort(t.begin(), t.end());
        ans = min(ans, t[q-1] - a[i]);
    }
    printf("%lld\n", ans);
}