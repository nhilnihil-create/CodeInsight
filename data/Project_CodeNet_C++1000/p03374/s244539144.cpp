/*
Submitted With (^^) by -> Hossam ^_^
 _____________________
|     ___     ___     |
|    (^_^)   (^_^)    |
|   /( | )\_/( | )\   |
|_____|_|_____|_|_____|
*/

#include <bits/stdc++.h>

using namespace std;

inline void prep()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}

#define X first
#define Y second
#define ll long long
#define inf (0x7fffffffffffffff)
#define all(x) x.begin(), x.end()

const int mod = (int)1e9 + 7;
const int MX = (int)2e5 + 1;

int main()
{
    prep();

    int n;
    cin >> n;

    ll c;
    cin >> c;

    vector<pair<ll, ll>> v(n + 1);
    vector<ll> fwacc(n + 1), bcacc(n + 1);

    v[0] = make_pair(0, 0);

    //input
    for(int i = 1; i <= n; ++i){
        cin >> v[i].X >> v[i].Y;
    }

    //patial_forward
    for(int i = 1; i <= n; ++i){
        fwacc[i] = v[i].Y + fwacc[i - 1];
    }

    //partial_backward
    bcacc[n] = v[n].Y;
    for(int i = n - 1; i > 0; --i){
        bcacc[i] = bcacc[i + 1] + v[i].Y;
    }

    ll res = 0;

    vector<int> bst_idx(n + 1);
    vector<int> bst_idx2(n + 1);
    int idx = 0;
    ll bst = 0;

    //only forward
    for(int i = 1; i <= n; ++i){
        bst = fwacc[i] - v[i].X;
        if(bst > res){
            res = bst;
            idx = i;
        }
        bst_idx[i] = idx;
    }

    // v.push_back({c, 0});

    bst = 0;
    idx = n;
    // backward only
    for(int i = n; i > 0; --i){
        ll cur = bcacc[i] - (c - v[i].X);
        if(cur > bst){
            bst = cur;
            idx = i;
        }
        bst_idx2[i] = idx;
    }
    bst_idx2[0] = idx;

    res = max(res, bst);

    // combined
    for(int bc_idx = n; bc_idx > 1; --bc_idx){        
        int fw_idx = bst_idx[bc_idx - 1];
        ll dist_bc = c - v[bc_idx].X;
        ll dist_fw = v[fw_idx].X;
        res = max(res, bcacc[bc_idx] + fwacc[fw_idx] - (2 * min(dist_fw, dist_bc) + max(dist_fw, dist_bc)));
    }

    for(int fw_idx = 1; fw_idx < n; ++fw_idx){
        int bc_idx = bst_idx2[fw_idx + 1];
        ll dist_fw = v[fw_idx].X;
        ll dist_bc = c - v[bc_idx].X;
        res = max(res, bcacc[bc_idx] + fwacc[fw_idx] - (2 * min(dist_fw, dist_bc) + max(dist_fw, dist_bc)));
    }

    cout << res << endl;

    return 0;
}