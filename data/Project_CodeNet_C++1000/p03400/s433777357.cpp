#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, d, x; cin >> n >> d >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    rep(i,n){
        ans += (d - 1) / a[i] + 1;
    }
    ans += x;
    cout << ans << endl;
}
