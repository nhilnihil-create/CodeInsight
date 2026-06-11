#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
//a 普通の刀 b 投げる刀
int main() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    sort(all(a));
    sort(all(b));
    int mx = a[n-1];
    int ans = 0;
    reverse(all(b));
    rep(i,n){
        if(b[i]<= mx || h <= 0) break;
        h-=b[i];
        ans++;
    }
    if(h <= 0) { cout << ans << endl;}
    else{
        ans += (h+mx-1)/mx;
        cout << ans << endl;
    }
    return 0;   
}