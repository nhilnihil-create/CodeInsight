#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    int n, k; cin >> n >> k;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        m[a]++;
    }

    if(m.size() <= k){
        cout << 0 << endl;
        return 0;
    }

    V<P<int, int> > v;
    for(auto p : m){
        v.push_back(make_pair(p.second, p.first));
    }
    sort(all(v));

    int ans = 0;
    for(int i = 0; i < m.size() - k; i++){
        ans += v[i].first;
    }
    cout << ans << endl;

}

