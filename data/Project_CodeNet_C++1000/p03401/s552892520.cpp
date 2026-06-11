#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t n;
    cin >> n;
    int64_t a[110000];
    a[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    a[n+1] = 0;
    int64_t allCost = 0;
    for(int i=0; i<=n; i++){
        allCost += abs(a[i+1] - a[i]);
    }
    for(int i=0; i<n; i++){
        int64_t ans = allCost;
        ans -= abs(a[i+1] - a[i]);
        ans -= abs(a[i+2] - a[i+1]);
        ans += abs(a[i+2] - a[i]);
        cout << ans << endl;
    }
    return 0;
}