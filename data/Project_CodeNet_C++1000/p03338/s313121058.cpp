#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        vector<pair<bool, bool>> check(26, make_pair(false, false));
        string x = s.substr(0,i);
        string y = s.substr(i);
        for (int j = 0; j < x.length(); j++) {
            check[x[j]-'a'].first = true;
        }
        for (int j = 0; j < y.length(); j++) {
            check[y[j]-'a'].second = true;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (check[i].first && check[i].second)
                count ++;
        }
        ans = max(ans,count);
    }
    cout << ans << endl;
}