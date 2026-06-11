#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<string,string> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    string s;
    map<P,ll> cnt;
    cin >> n >> s;
    for (int i = 0;i < (1<<n);++i) {
        string k1 = "",k2 = "";
        for (int j = 0;j < n;++j) if ((i>>j)&1) k1 += s[j];
        for (int j = n-1;j >= 0;--j) if (((i>>j)&1)^1) k2 += s[j];
        cnt[P(k1,k2)]++;
    }
    ll ans = 0;
    for (int i = 0;i < (1<<n);++i) {
        string k1 = "",k2 = "";
        for (int j = 0;j < n;++j) if ((i>>j)&1) k1 += s[2*n-j-1];
        for (int j = n-1;j >= 0;--j) if (((i>>j)&1)^1) k2 += s[2*n-j-1];
        ans += cnt[P(k1,k2)];
    }
    cout << ans << endl;
    return 0;
}