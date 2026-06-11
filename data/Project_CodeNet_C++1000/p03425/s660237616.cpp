/**
 *    author:  FromDihPout
 *    created: 2020-08-15
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<char> letter = {'M', 'A', 'R', 'C', 'H'};
    const int L = letter.size();
    
    int n;
    cin >> n;
    vector<int> cnt(L);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int i = 0; i < L; i++) {
            if (s[0] == letter[i]) {
                cnt[i]++;
                break;
            }
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < L; i++) {
        for (int j = i + 1; j < L; j++) {
            for (int k = j + 1; k < L; k++) {
                ans += (long long) cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}