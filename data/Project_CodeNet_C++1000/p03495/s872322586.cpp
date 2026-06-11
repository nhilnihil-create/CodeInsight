#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using  namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (m.count(x) == 0) {
            m.emplace(x, 0);
        }
        m[x]++;
    }
    vector<int> a(m.size());
    int i = 0;
    for (auto v:m) {
        a[i++] = v.second;
    }
    sort(a.begin(), a.end());
    int sum = 0;
    if (a.size() < k){
        cout << sum << endl;
        return 0;
    }
    for (i = 0; i < a.size() - k; i++) {
        sum += a[i];
    }
    cout << sum << endl;
}
