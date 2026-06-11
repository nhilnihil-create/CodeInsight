#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    mp['a'] = 0, mp['b'] = 0, mp['c'] = 0;
    rep(i, s.size()) {
        mp[s[i]]++;
    }
    int abc[3];
    int ma = 0;
    for (auto m : mp) {
        ma = max(ma, m.second);
    }
    for (auto m : mp) {
        int abc = m.second;
        if (ma-abc > 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
