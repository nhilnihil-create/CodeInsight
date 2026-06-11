#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    rep(i, 0, m) cin >> l[i] >> r[i];
    vector<int> a(100005);
    rep(i, 0, m){
        a[l[i]]++; a[r[i]+1]--;
    }
    int ans = 0;
    int sum = 0;
    rep(i, 0, 100005){
        sum += a[i];
        if(sum == m) ans++;
    }
    cout << ans << endl;
    return 0;
}

