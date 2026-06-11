#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15); 
    int n, N; 
    cin >> n;
    N = (1 << n); 
    vector<int> a(N); 
    vector<pair<int, int>> b(N, make_pair(0, 0));  
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) {
        b[i].first = a[0];
        for (int j = i; j != 0; j = (j - 1) & i) {
            if (a[j] > b[i].first) b[i].second = b[i].first, b[i].first = a[j];
            else if (a[j] > b[i].second) b[i].second = a[j]; 
        }
    }
/*
    for (int i = 1; i < N; ++i) {
        cerr << b[i].first << ' ' << b[i].second << endl; 
    }
*/
    int ans = 0; 
    for (int i = 1; i < N; ++i) {
        ans = max(ans, b[i].first + b[i].second); 
        cout << ans << endl; 
    }
    return 0;  
}