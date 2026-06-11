#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,k;
    cin >> n >> k;
    
    double ans=0.0;

    for (int d = 1; d <= n; d++){
        
        int cnt=max(0.0,ceil(log2((double)k/(double)d)));
        ans=ans+pow(0.5,(double)cnt)/(double)n;
    }

    cout << fixed << setprecision(12) << ans << endl;
}