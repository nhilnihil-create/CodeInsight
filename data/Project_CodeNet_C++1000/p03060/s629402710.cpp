#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n;
    cin >> n;
    
    vector<int> v(n), c(n);
    rep(i,n) cin >> v[i];
    rep(i,n) cin >> c[i];
    
    int ans = 0;
    rep(i,n) {
        if(v[i] - c[i] > 0)
            ans += v[i] - c[i];
    }
    
    cout << ans << endl;
    
    
    return 0;
}
