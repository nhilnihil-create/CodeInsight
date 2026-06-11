#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n;
    map<int , int> mp;
    rep(i,n){
        int d;
        cin >> d;
        mp[d]++;
    }
    bool ok = true;
    cin >> m;
    rep(i,m){
        int t;
        cin >> t;
        mp[t]--;
        if(mp[t]<0){
            ok = false;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}