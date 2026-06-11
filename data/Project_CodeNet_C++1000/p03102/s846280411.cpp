/*
      author  : nishi5451
      created : 14.08.2020 23:56:55
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    int ans = 0;
    rep(i,n){
        int now = c;
        rep(j,m){
            int a;
            cin >> a;
            now += a*b[j];
        }
        if(now > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}