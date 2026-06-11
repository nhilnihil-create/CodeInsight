/**
 *    author:  FromDihPout
 *    created: 2020-08-11
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    map<int,int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    
    int ans = 0;
    for (auto i : freq) {
        if (i.first != i.second) {
            ans += i.second >= i.first ? i.second - i.first : i.second;
        }
    }
    cout << ans << '\n';
    return 0;
}