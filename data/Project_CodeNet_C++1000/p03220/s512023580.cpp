#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, a;
    cin >> n >> t >> a;
    int h[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    
    pair<double, int> ans(DBL_MAX,0);
    for (int i = 0; i < n; i++) {
        double temp = abs(a-(t-h[i]*0.006));
        if (temp < ans.first) {
            ans.first = temp;
            ans.second = i+1;
        }
    }

    cout << ans.second << endl;
}