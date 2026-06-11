#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;


int main() {
    int x, y, z, k, m;
    vector<ll>a;
    vector<ll>b;
    vector<ll>c;
    vector<ll>e;
    vector<ll>ans;
    ll val;
    cin >> x >> y >> z >> k;
    for (int i = 0; i < x; i++) {
        cin >> val;
        a.push_back(val);
    }
    for (int i = 0; i < y; i++) {
        cin >> val;
        b.push_back(val);
    }
    for (int i = 0; i < z; i++) {
        cin >> val;
        c.push_back(val);
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            e.push_back(a[i]+b[j]);
        }
    }
    sort(e.begin(), e.end(), std::greater<ll>());


    m = (k < e.size()) ? k : e.size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < z; j++) {
            ans.push_back(e[i]+c[j]);
        }
    }
    sort(ans.begin(), ans.end(), std::greater<ll>());

    for (int i = 0; i < k; i++) {
        cout << ans[i] << endl;
    }
}
