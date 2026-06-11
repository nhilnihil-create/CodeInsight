#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    int t, a;
    cin >> n;
    cin >> t >> a;
    
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v.at(i);
    }
    
    int ans = -1;
    double minDiff = 100000;
    
    for (int i=0; i<n; i++) {
        double diff = abs(a - (t - 0.006*v.at(i)));
        if (minDiff > diff) {
            minDiff = diff;
            ans = i + 1;
        }
    }
    
    cout << ans << endl;
    
    
}
