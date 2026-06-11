#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    rep(i, N) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    //b[i]を固定して、a[j] < b[i]となるjの値の数と、c[k] > b[i]となるkの値の数を求め
    //その積が、b[i]を中段に使う時の作り方の数となる。
    ll ans = 0;
    rep(i, N){
        //a[j] < b[i]を満たすjの個数
        ll r = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        //b[i] < c[k]を満たすkの個数
        ll l = c.end() - upper_bound(c.begin(), c.end(), b[i]);
        ans += r * l;
    }
    cout << ans << endl;
    return 0;
}