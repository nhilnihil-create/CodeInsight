//Solution by NurlashKO
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <stack>
#include <list>
#include <map>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int sz = 1e6;
#define pb push_back
 
int n, m, v, u, cnt[sz][2], was[sz], q[sz], l, r;
string s;
vector <int> a[sz];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    cin >> s;
    
    for (int i = 1; i <= m; i++) {
        cin >> v >> u;
        v--;u--;
        a[v].pb(u);
        a[u].pb(v);
        cnt[v][s[u] - 'A']++;
        cnt[u][s[v] - 'A']++;
    }
    for (int i = 0; i < n; i++) {
        if (!cnt[i][0] || !cnt[i][1]) {
            q[r++] = i;
            was[i] = 1;
        }
    }
    
    while (l < r) {
        v = q[l++];
        for (int to: a[v]) {
            cnt[to][s[v] - 'A']--;
            if (!was[to] && (!cnt[to][0] || !cnt[to][1])) {
                was[to] = 1;
                q[r++] = to;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!was[i]) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}