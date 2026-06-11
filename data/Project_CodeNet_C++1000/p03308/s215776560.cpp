#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int M = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            M = max(M, abs(a[i]-a[j]));
        }
    }
    cout << M << endl;
    return 0;
}