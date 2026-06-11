#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
#define ll long long
#define P pair<int,int>

signed main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1]){
            a[i] = -1;
            ans++;
        }
    }
    cout << ans << endl;
}