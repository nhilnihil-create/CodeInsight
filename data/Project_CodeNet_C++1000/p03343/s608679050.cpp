#include<bits/stdc++.h>
using namespace std;

#define p_ary(ary,a,b,i) do { cout << "["; for (int i = a;i <= b;++i) cout << ary[i] << (b == i ? "]\n" : ", "); } while(0)
#define p_map(map,it) do {cout << "{";for (auto it = map.begin();;++it) {if (it == map.end()) {cout << "}\n";break;}else cout << "" << it->first << "=>" << it->second << ", ";}}while(0)

int main() {
    int n,k,q,a[2010];
    cin >> n >> k >> q;
    for (int i = 0;i < n;++i) cin >> a[i];
    a[n] = -1;

    int ans = INT_MAX;
    for (int i = 0;i < n;++i) {
        int l = 0;
        vector<int> b,temp;
        for (int j = 0;j <= n;++j) {
            if (a[j] < a[i]) {
                if (l >= k) {
                    sort(temp.begin(),temp.end());
                    for (int x = 0;x < temp.size()-k+1;++x) b.push_back(temp[x]);
                }
                l = 0;
                temp.clear();
            } else {
                l++;
                temp.push_back(a[j]);
            }
        }
        sort(b.begin(),b.end());
        if (b.size() >= q) ans = min(ans,b[q-1]-a[i]);
    }
    cout << ans << endl;
    return 0;
}