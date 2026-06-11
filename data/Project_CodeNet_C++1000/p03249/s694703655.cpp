#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
using namespace std;
int n;
/*int a[100020];
int b[100020];*/
pair<long long, int> d[100200];
map<long long, int> mp;
vector<int> ed[100200];
int sz[100200];
long long f[100200];
int par[100200];
void bad() {
    cout << "-1\n";
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i].first;
        d[i].second = i;
    }
    vector<pair<int, int> > ans;
    sort(d + 1, d + n + 1);
    for (int i = 1; i <= n; i++) mp[d[i].first] = i;

    for (int i = n; i > 1; i--) {
        sz[i]++;
        long long x = d[i].first - (n - 2 * sz[i]);
        if (mp[x] == 0) bad();
        else {
            sz[mp[x]] += sz[i];
            ans.push_back(make_pair(d[i].second, d[mp[x]].second));
            f[mp[x]] += f[i] + sz[i];
        }
        if (sz[i] > n) bad();
    }
    sz[1]++;
    if (sz[1] != n) bad();
    if (f[1] != d[1].first) bad();
    //check(ans);
    for (auto it: ans) cout << it.first << " " << it.second << "\n";
    return 0;
}