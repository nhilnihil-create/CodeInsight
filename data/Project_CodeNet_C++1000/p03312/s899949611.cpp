#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 5;
int n, a[5], f[N], ans = 1e18 + 7;

int cnp1(int l, int r, int i){
    int res = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(f[mid] <= f[i] - f[mid]) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    return res;
}

int cnp2(int l, int r, int id){
    int res = id;
    while(l <= r){
        int mid = (l + r) / 2;
        if(f[mid] - f[id] <= f[n] - f[mid])res = mid, l = mid + 1;
        else r = mid - 1;
    }
    return res;
}

int solve(int l, int mid, int r){
    int res = 0;
    a[1] = f[l]; a[2] = f[mid] - f[l];
    a[3] = f[r] - f[mid]; a[4] = f[n] - f[r];
    for(int i = 1 ; i<= 4; ++ i)
        for(int j = i + 1; j <= 4; ++ j) res = max(res, abs(a[i] - a[j]));
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> f[i], f[i] += f[i - 1];
    for(int i = 2; i < n - 1; ++ i){
        int mid_r, mid_l;
        int l = cnp1(1, i, i);
        if(f[i] - 2 * f[l] < 2 * f[l + 1] - f[i]) mid_l = l;
        else mid_l = l + 1;
        int r = cnp2(i + 1, n, i);
        if(f[n] + f[i] - 2 * f[r] < 2 * f[r + 1] - f[i] - f[n]) mid_r = r;
        else mid_r = r + 1;
        ans = min(ans, solve(mid_l, i, mid_r));
    }
    cout << ans;
}
