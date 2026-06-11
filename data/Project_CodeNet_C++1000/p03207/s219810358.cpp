#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(),p.end(),greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            ans += p[i] / 2;
        } else {
            ans += p[i];
        }
    }
    cout << ans << "\n";
    return 0;
}