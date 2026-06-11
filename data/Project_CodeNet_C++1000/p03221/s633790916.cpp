#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() 
{
    int n, m;
    cin >> n >> m;
    map<int, priority_queue<pair<int,int>>> mp;
    rep(i,m) {
        int p, y;
        cin >> p >> y;
        mp[p].emplace(-y, i);
    }

    vector<pair<int, int>> V(m); // <p,x>
    for (auto v : mp) {
        int p = v.first;
        auto Q = v.second;
        int x = 1;
        while(!Q.empty()) {
            auto pir = Q.top(); Q.pop();
            V[pir.second] = make_pair(p, x);
            x++;
        }
    }

    rep(i,m) {
        printf("%06d%06d\n", V[i].first, V[i].second);
    }

    
    
    return 0;
}
