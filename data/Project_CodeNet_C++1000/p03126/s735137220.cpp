#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    rep(i,n){
        int k;
        cin >> k;
        rep(j,k){
            int a;
            cin >> a;
            mp[a]++;
        }
    }
    int ans = 0;
    rep(i,m+1){
        if(mp[i]==n) ans++;
    }
    cout << ans << endl;

    return 0;
}