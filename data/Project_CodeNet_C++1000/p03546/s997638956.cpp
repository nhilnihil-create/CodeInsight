#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> vrow(10);
    vector<vector<int>> values(10,vrow);
    for (int i=0; i<10; i++) for (int j=0; j<10; j++) cin >> values[i][j];
    vector<vector<pair<int,ll>>> paths(10);
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (i!=j) paths[i].push_back(make_pair(j,values[i][j]));
        }
    }
    vector<ll> finalvalues(10,0);
    priority_queue<pair<ll,int>> moves;
    for (int i=0; i<10; i++) {
        vector<ll> dists(10,1000000000);
        dists[i] = 0;
        moves.push(make_pair(0,i));
        while (moves.size()>0) {
            pair<ll,int> curr = moves.top();
            moves.pop();
            for (auto j : paths[curr.second]) {
                if (-curr.first+j.second >= dists[j.first]) continue;
                dists[j.first] = -curr.first+j.second;
                moves.push(make_pair(curr.first-j.second,j.first));
            }
        }
        finalvalues[i] = dists[1];
    }
    int val;
    ll res = 0;
    for (int i=0; i<h; i++) for (int j=0; j<w; j++) {
        cin >> val;
        if (val==-1) continue;
        res+=finalvalues[val];
    }
    cout << res;
    return 0;
}