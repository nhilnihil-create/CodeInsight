#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    map<int,int> m;
    int d[n];
    rep(i,n){
        cin >> d[i];
        m[d[i]]++;
    }
    if(n >= 23) {
        bool can = true;
        for(auto x : m) {
            if(x.second > 2) can = false;
            if(x.first == 12 && x.second >= 2) can = false;
            if(x.first == 0) can = false;
        }
        cout << (can? "1" : "0") << endl;
        return 0;  
    }
    int ans = 0;
    rep(i,1<<n){
        int a[n+1] = {};
        a[n] = 0;
        rep(j,n){
            if(d[j] == 0) a[j] = 0;
            else if(i & (1<<j)) a[j] = d[j];
            else a[j] = 24-d[j];
        }
        int c = 25;
        for(int j = 0; j <= n; j++){
            for(int k = j+1; k <= n; k++) {
                int g = min(abs(a[j]-a[k]),24-abs(a[j]-a[k]));
                c = min(c,g);
            }
        }
        ans = max(ans,c);
    }
    cout << ans << endl;
    return 0;
}