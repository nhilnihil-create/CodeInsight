#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int ans1 = a[n - 1];
    int ans2 = 0;
    int k = (ans1 + 1) / 2;
    for(int i = 0; i < n; i++){
        if(abs(k - a[i]) < abs(k - ans2))
            ans2 = a[i];
     }
    cout << ans1 << " " << ans2 << endl;
}