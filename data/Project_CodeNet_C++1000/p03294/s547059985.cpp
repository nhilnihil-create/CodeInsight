#include <bits/stdc++.h>
using namespace std;
int main(){
        int n; cin >> n;
        int ans = 0;
        for (int x = 0; x < n; ++x){
            int q; cin >> q;
            ans += q - 1;
        }
        cout << ans << endl;
    return 0;
}
/*here (a*b*c-1) % k*/
