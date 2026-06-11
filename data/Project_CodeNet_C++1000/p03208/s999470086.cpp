#include <bits/stdc++.h>
using namespace std;  

int main(){
    int n, k, h[100000], ans;
    cin >> n >> k;
    for ( int i = 0; i < n; i++ ) {
        cin >> h[i];
    }
    sort(h, h+n);
    
    ans = INT_MAX;
    for ( int i = k-1; i < n; i++ ) {
        ans = min(ans, h[i] - h[i-k+1]);
    }
    cout << ans << endl;
    
    return (0);
}