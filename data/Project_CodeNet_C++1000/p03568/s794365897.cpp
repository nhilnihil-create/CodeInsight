#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int odd = 1;
    rep(i, 0, n){
        if(a[i]%2) odd *= 1;
        else odd *= 2;
    }
    int ans = pow(3, n);
    cout << ans - odd << endl;
    return 0;
}
