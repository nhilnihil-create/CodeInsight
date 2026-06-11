#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    int n;cin>> n;
    int h[n];
    rep(i,n)cin >> h[i];
    int ans = 0;
    int nh = 1;
    rep(d,100){
        int f = 0;
        rep(i,n){
            if(h[i] > 0){
                h[i]--;
                f = 1;
            }
            else if(f){
                ans++;
                f = 0;
            }
        }
        if(f)ans++;


    }
    cout << ans;

    return 0;
}