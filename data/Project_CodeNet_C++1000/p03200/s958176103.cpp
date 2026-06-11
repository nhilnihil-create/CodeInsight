#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    vector<int> v;
    long long ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'W') {
            v.push_back(i);
        }
    }
    for(int i = 0; i < v.size(); i++) {
        ans += (v[i] - i);
    }
    cout << ans << "\n";
    return 0;
}