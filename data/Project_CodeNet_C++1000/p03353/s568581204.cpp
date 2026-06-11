#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    set<string> dic;
    for (int i = 1; i <= k; i++) {
        rep(j, n-i+1) {
            string c;
            rep(l, i) {
                c.push_back(s[j+l]);
            }
            dic.insert(c);
        }
    }
    // int i = 0;
    // for (string word : dic) {
    //     i++;
    //     if (i == k) {
    //         cout << word << endl;
    //     }
    // }
    auto itr = dic.begin();
    rep(i, k-1) {
        itr++;
    }
    cout << *itr << endl;
}