#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    a.push_back(-1);

    int ans = 1e9;
    for (int i = 0;i < n;++i) {
        vector<int> b,c;
        for (int j = 0;j <= n;++j) {
            if (a[j] >= a[i]) c.push_back(a[j]);
            else {
                if (c.size() >= k) {
                    sort(c.begin(),c.end());
                    for (int x = 0;x < c.size()-k+1;++x) b.push_back(c[x]);
                }
                c.clear();
            }
        }
        if (b.size() >= q) {
            sort(b.begin(),b.end());
            ans = min(ans,b[q-1]-b[0]);
        }
    }
    cout << ans << endl;
    return 0;
}