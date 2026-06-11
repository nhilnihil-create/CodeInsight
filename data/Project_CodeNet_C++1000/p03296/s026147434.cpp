#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i, n ) cin >> a[i];
    a[n] = -1;
    int cnt = 1;
    int ans = 0;
    rep(i, n+1) {
        if ( a[i] == a[i+1] ) {
            ++cnt;
        }
        else {
            ans += cnt / 2;
            cnt = 1;
        }
//        cout << cnt << endl;
    }
    cout << ans << endl;
    return 0;
}