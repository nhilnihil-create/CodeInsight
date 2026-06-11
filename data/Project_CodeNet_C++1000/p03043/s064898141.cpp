#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n,k;
    cin >> n >> k;
    
    double ans=0.0;

    for (int d = 1; d <= n; d++){
        int scr=d;
        int cnt=0;
        while(scr<k){
            scr=scr*2;
            cnt++;
        }
        ans=ans+(1.0/(double)n)*pow(0.5,(double)cnt);
    }

    cout << fixed << setprecision(12) << ans << endl;
}