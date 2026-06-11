#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    vector<ll> x(n), t(n);
    for (int i=0; i<n; i++) cin >> x[i];
    
    t = x;
    sort(t.begin(), t.end());
    int mid = (n-2) / 2;
    for (int i=0; i<n; i++) {
        if (x[i] <= t[mid]) cout << t[mid+1] << endl;
        else cout << t[mid] << endl;
    }
    
    return 0;
}