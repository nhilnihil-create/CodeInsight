#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    vector<string> sub;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 0; j < n - i + 1; ++j) {
            sub.emplace_back(s.substr(j, i));
        }
    }
    sort(sub.begin(), sub.end());
    sub.erase(unique(sub.begin(), sub.end()), sub.end());
    sort(sub.begin(), sub.end());
    cout << sub[k - 1] << endl;
}
