#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    double n, k;
    cin >> n >> k;
    
    double cnt = 1 / n, half = 1, ans = 0;
    while(n > 0) {
        if(n >= k) {
            //cout << cnt * half << endl;
            ans += cnt * half;
            n--;
        }
        else {
            k /= 2;
            half *= 0.5;
        }
    }
    
    cout << fixed << setprecision(10) << ans << endl;
    
    
    
    return 0;
}
