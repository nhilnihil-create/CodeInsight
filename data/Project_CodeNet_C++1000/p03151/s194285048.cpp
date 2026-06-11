#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), diff(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int minus = 0;
    for(int i = 0; i < n; i++){
        cin >> b[i];
        diff[i] = a[i] - b[i];
        if(diff[i] < 0){
            minus += diff[i];
        }
    }
    sort(diff.begin(), diff.end());
    vector<bool> changed(n, false);
    int i = 0, j = n-1;
    while(diff[i] < 0){
        if(diff[j] < 0){
            cout << -1 << endl;
            return 0;
        }
        if(-diff[i] <= diff[j]){
            diff[j] += diff[i];
            changed[i] = changed[j] = true;
            i++;
        } else {
            diff[i] += diff[j];
            changed[i] = changed[j] = true;
            j--;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += changed[i];
    }
    cout << ans << endl;
    return 0;
}