#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> to, ot;
vector<int> top, seen;

void dfs(int v) {
    if(seen[v])return;
    seen[v] = true;
    for(auto i : to[v])dfs(i);
    top.push_back(v);
}


int main()
{
    cin >> n >> m;
    to.resize(n), ot.resize(n), seen.resize(n);

    for(int i = 0; i < m + n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        to[a].push_back(b);
        ot[b].push_back(a);
    }
    for(int i = 0; i < n; i++)dfs(i);

    reverse(top.begin(), top.end());
    for(auto i : top) cerr << i << " : ";
    cerr << endl;
    map<int,int> mp;
    for(int i = 0; i < n; i++)mp[top[i]] = i;

    for(int i = 0; i < n; i++) {
        int naind = -1, nax = -1;

        for(auto j : ot[i]) {
            if(mp[j] > naind) {
                naind = mp[j];
                nax = j;
            }
        }
        cout << nax + 1 << endl;
    }


}