#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define rrep(i,n) for (int i = (n - 1);i >= 0;i--)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    int num = 0;
    rep(i,n){
        if(a[i+1]-a[i] != 0){
            ans += (i+1-num)/2;
            num = i + 1;
        }
    }
    cout << ans << endl;
}