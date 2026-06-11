#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using Graph = vector<vector<pair<int, int>>>;

const ll INF = 1001001001;

int main(){
    int n; cin >> n;
    ll c; cin >> c;
    vector<ll> x(n), v(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> v[i];
    }
    vector<ll> clock(n+1), c_clock(n+1);
    // colckwise, couterclockwiseにi個とった
    for(int i = 0; i < n; i++){
        clock[i + 1] = clock[i] + v[i];
    }
    for(int i = 0; i < n; i++){
        c_clock[i + 1] = c_clock[i] + v[n - 1 - i];
    }
    vector<ll> opt_clock(n+1), opt_c_clock(n+1);
    //左からi個まで取れる時の最大
    ll clock_max = 0, c_clock_max = 0;
    for(int i = 1; i - 1 <= n; i++){
        clock_max = max(clock_max, clock[i-1] - (i - 1 >= 1 ? x[i - 2] : 0));
        c_clock_max = max(c_clock_max, c_clock[i-1] - (i - 1 >= 1 ? c - x[n - i + 1] : 0));
        opt_clock[i - 1] = clock_max;
        opt_c_clock[i - 1] = c_clock_max;
    }
    ll ans = 0;
    ll tmp;
    for(int i = 0; i <= n; i++){
        tmp = c_clock[i] - (i > 0 ? 2 * (c - x[n - i]) : 0);
        tmp += opt_clock[n - i];
        ans = max(ans, tmp);
    }
    for(int i = 0; i <= n; i++){
        tmp = clock[i] - (i > 0 ? 2 * x[i - 1] : 0);
        tmp += opt_c_clock[n - i];
        ans = max(ans, tmp);
    }
    cout << ans << endl;

}
