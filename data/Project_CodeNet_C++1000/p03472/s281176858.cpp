#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n, h;
    cin >> n >> h;
    vector<int> a(n), b(n);
    
    for (int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    
    int ans = 0;
    int sum = 0;
    
    for (int i=0; i<n; i++){
        if(a[0] <= b[i]){
            sum += b[i];
            ans++;
            if(sum >= h){
                cout << ans << endl;
                return 0;
            }
        }
    }
    
    while(sum < h){
        sum += a[0];
        ans++;
    }
    
    cout << ans << endl;
}
