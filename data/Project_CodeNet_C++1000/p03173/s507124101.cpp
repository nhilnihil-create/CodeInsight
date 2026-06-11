#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, r, n) for (int i = (r); i <= (n); i++)

using ll = long long;
using namespace std;

ll a[500], sum[500], ans[500][500];
const ll INF = 100100100100100;

ll solve(int left, int right){
    if(right - left <= 1) return 0;
    if(ans[left][right] != 0) return ans[left][right];
    ll res = INF;
    loop(i, left+1, right-1) res = min(res, solve(left,i) + solve(i,right));
    res += sum[right] - sum[left];
    return ans[left][right] = res;
}

int main(){
    int n; cin >> n;
    rep(i,n) cin >> a[i], sum[i+1] = a[i]+sum[i];
    cout << solve(0,n) << endl;
    return 0;
}