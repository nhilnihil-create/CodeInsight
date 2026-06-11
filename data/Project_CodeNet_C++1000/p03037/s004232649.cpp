#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int n, m;
    cin >> n >> m;
    
    int ans_l = 1, ans_r = n;
    rep(i,m) {
        int l, r;
        cin >> l >> r;
        
        ans_l = max(ans_l, l);
        ans_r = min(ans_r, r);
    }
    
    cout << max(ans_r - ans_l + 1, 0) << endl;
    
    
    return 0;
}
