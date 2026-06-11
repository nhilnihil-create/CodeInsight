#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    vector<int> w(n),s(n),v(n);
    vector<P> p(n);
    for (int i = 0;i < n;++i) cin >> w[i] >> s[i] >> v[i];
    for (int i = 0;i < n;++i) p[i] = P(w[i]+s[i],i);
    sort(p.begin(),p.end());
    vector<vector<ll>> dp(n+1,vector<ll>(20010,0));
    for (int i = 0;i < n;++i) {
        int x = p[i].second;
        dp[i+1] = dp[i];
        for (int j = 0;j <= s[x];++j) if (j+w[x] < 20010 && dp[i+1][j+w[x]] < dp[i][j]+v[x]) dp[i+1][j+w[x]] = dp[i][j]+v[x];
    }
    cout << *max_element(dp[n].begin(),dp[n].end()) << endl;
    return 0;
}