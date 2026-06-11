#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    long long int ans = 0;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        mp[a]++;
    }
    auto begin = mp.begin(), end = mp.end();
    for(auto iter = begin; iter != end; iter++) {
        //cerr << iter->first << " " << iter->second << endl;
        if(iter->first < iter->second) ans += iter->second - iter->first;
        else if(iter->first > iter->second) ans += iter->second;
    }
    cout << ans << '\n';

    return 0;
}
