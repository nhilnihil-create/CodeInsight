#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n, T, c, t, ans=10000;
    cin >> n >> T;
    for (int i=0; i<n; i++){
        cin >> c >> t;
        if (t <= T){
            ans = min(c, ans);
        }
    }
    if (ans == 10000){
        cout << "TLE" << endl;
    } else{
        cout << ans << endl;
    }
    return 0;
}
