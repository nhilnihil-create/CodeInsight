#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

//11 -> 21
int main() {
    vector<int> a(3);
    rep(i,3) cin >> a[i];
    sort(all(a));
    int ans = a[2]*2 - a[0] - a[1];
    if(ans%2){
        ans+=3;
    }
    cout << ans/2 << endl;
    return 0;
}
