/**
 *    author:  FromDihPout
 *    created: 2020-08-16
**/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n+1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    sort(all(cnt), greater<int>());
    
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += cnt[i];
    }
    cout << n - sum << '\n';
    return 0;
}