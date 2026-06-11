#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

bool is_valid(vector<pair<long long, int>> &D, vector<pair<int, int>> &edges){
    int N = D.size();
    vector<vector<int>> G(N);
    for(auto x : edges){
        G[x.first].push_back(x.second);
        G[x.second].push_back(x.first);
    }
    queue<pair<int, long long>> que;
    vector<bool> vis(N, false);
    que.push(make_pair(0, 0));
    long long cnt = 0;
    while(!que.empty()){
        auto q = que.front();
        que.pop();
        if(vis[q.first]) continue;
        vis[q.first] = true;
        cnt += q.second;
        for(auto x : G[q.first])
            que.push(make_pair(x, q.second+1));
    }
    return cnt == D[0].first;
}

int main(){
    long long N;
    cin >> N;
    vector<pair<long long, int>> D(N);
    for(int i=0; i<N; i++){
        long long tmp;
        cin >> tmp;
        D[i] = make_pair(tmp, i);
    }
    sort(D.begin(), D.end(), greater<pair<long long, int>>());

    vector<int> idx2idx(N);
    for(int i=0; i<N; i++)
        idx2idx[i] = D[i].second;

    map<long long, int> d2idx;
    for(int i=0; i<N; i++)
        d2idx[D[i].first] = i;

    vector<long long> E(N, 1);
    vector<pair<int, int>> edges;
    for(int i=0; i<N-1; i++){
        long long d0 = D[i].first;
        long long d1 = D[i].first + 2 * E[i] - N;
        auto itr = d2idx.find(d1);
        if(itr == d2idx.end() || i == d2idx[d1]){
            cout << -1 << endl;
            return 0;
        }
        edges.push_back(make_pair(i, d2idx[d1]));
        E[d2idx[d1]] += E[i];
    }

    if(!is_valid(D, edges)){
        cout << -1 << endl;
        return 0;
    }

    for(auto x : edges)
        cout << idx2idx[x.first]+1 << " " << idx2idx[x.second]+1 << endl;

    return 0;
}