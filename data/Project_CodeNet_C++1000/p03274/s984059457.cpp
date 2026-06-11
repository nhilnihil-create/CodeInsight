#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

int main(void){
    // Your code here!
    int n, k;
    cin >> n >> k;
    
    vector<int> x(n);
    for (int i=0; i<n; i++) cin >> x[i];
    
    int ans = INT_MAX;
    
    for (int i=0; i<n; i++){
        
        // l -> r
        if(i+k-1 < n){
            // cout << "l: " << i << " r: " << i+k << endl;
            ans = min(ans, abs(x[i]) + abs(x[i] - x[i+k-1]));
            ans = min(ans, abs(x[i+k-1]) + abs(x[i] - x[i+k-1]));
        }
        
    }
    cout << ans << endl;
}
