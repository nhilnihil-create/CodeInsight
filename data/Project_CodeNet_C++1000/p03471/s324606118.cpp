#include <bits/stdc++.h>
using namespace std;
int main(){
        int n, k; cin >> n >> k;
        for (int q = 0; q <= n; ++q){
            for (int w = 0; w <= n-q; ++w){
                int e = n - q - w;
                if (e < 0) break;
                if (q * 10000 + w * 5000 + e * 1000 == k){
                    cout << q << " " << w << " " << e << endl;
                    return 0;
                }
            }
        }
        cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}
