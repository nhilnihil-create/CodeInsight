#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) {
            if(n&1) {
                if(j != (n-i)) v.push_back(make_pair(i, j));
            } else {
                if(j != (n-i+1)) v.push_back(make_pair(i, j));
            }
        }
    }

    cout << v.size() << '\n';
    for(int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " " << v[i].second << '\n';
    }

    return 0;
}
