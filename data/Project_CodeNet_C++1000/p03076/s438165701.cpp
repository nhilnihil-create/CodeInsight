#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 100000

int main(){
    int ans = 0;
    int MAX = 0;
    rep(i, 5){
        int t;
        cin >> t;
        int am = 10 - t % 10;
        if(am == 10) am = 0;
        ans += t + am;
        MAX = max(MAX, am);
    }
    cout << ans - MAX << endl;
    
}