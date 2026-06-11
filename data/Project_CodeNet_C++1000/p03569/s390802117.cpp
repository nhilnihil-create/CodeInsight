#include <bits/stdc++.h>
using namespace std;
int main () {
    string s;
    cin >> s;
    string a = "";
    vector<int> v;
    int k = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'x') {
            a += s[i];
            v.push_back(k);
            k = 0;
        }
        else {
            k++;
        }
    }
    v.push_back(k);
    string b = a;
    reverse(b.begin(), b.end());
    if (a != b) {
        puts("-1");
        return 0;
    }
    int ans = 0;
    for (int l = 0, r = v.size()-1; l < r; l++, r--) {
        ans += abs(v[l]-v[r]);
    }
    cout << ans << endl;
}