#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> d(13, 0);
    d[0]++;
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        d[c]++;
        if(d[c] > 2) {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << 13); i++) {
        bitset<13> bit(i);
        vector<int> v;
        for(int j = 0; j < 13; j++) {
            if(d[j] == 1) {
                if(bit[j]) {
                    v.push_back(j);
                } else {
                    v.push_back(24 - j);
                }
            }
            if(d[j] == 2) {
                v.push_back(j);
                v.push_back(24 - j);
            }
        }
        int ta = INT_MAX;
        for(int x = 0; x < v.size(); x++) {
            for(int y = x + 1; y < v.size(); y++) {
                int tmp = max(v[x], v[y]) - min(v[x], v[y]);
                ta = min(ta, min(tmp, 24 - tmp));
            }
        }
        ans = max(ans, ta);
    }
    cout << ans << endl;
}