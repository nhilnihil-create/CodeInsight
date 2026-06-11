#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = n - 1; i >= 0; i--){
        int x = 1;
        while (x <= a[i]) x = (x << 1);
        int ok = - 1;
        int ng = i;
        while (abs(ok - ng) > 1){
            int mid = (ok + ng) / 2;
            if (a[mid] + a[i] <= x) ok = mid;
            else ng = mid;
        }
        if (ok != - 1 && a[ok] + a[i] == x){
            if (a[ok] != int(a[ok])) continue;
            a[ok] += 0.5;
            ans++;
        }
    }
    cout << ans << endl;
}