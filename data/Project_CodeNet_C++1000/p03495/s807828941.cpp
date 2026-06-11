#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, k, a;
    cin >> n >> k;
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        cin >> a;
        mp[a]++;
    }
    vector<int> v;
    for (auto iter=mp.begin(); iter!=mp.end(); iter++) {
        v.push_back(iter->second);
    }
    sort(v.begin(), v.end(), greater<>());
    int limit = min(k, (int)v.size());
    int result = n;
    for (int i=0; i<limit; i++) {
        result -= v[i];
    }
    cout << result << endl;
}