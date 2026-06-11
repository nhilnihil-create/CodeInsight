#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, m, d, t;
    map<int, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &d);
        mp[d]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        mp[t]--;
    }
    
    bool ok = true;
    for (auto u:mp) if (u.second < 0) ok = false;
    cout << (ok ? "YES" : "NO") << endl;
    
}