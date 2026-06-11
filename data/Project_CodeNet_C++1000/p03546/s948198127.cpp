#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
using pil = pair<int, ll>;

int main() {


    int h, w;

    cin >> h >> w;

    vector<vector<ll>> mp(10, vector<ll>(10, 0));

    for(int i = 0; i <= 9; ++i)
        for(int j = 0; j <= 9; ++j)
            cin >> mp[i][j];
        
    
    vector<ll> needMP(10, -1);

    ll sum = 0;

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {

            int value;
            cin >> value;

            if(value == -1)
                continue;

            if(needMP[value] != -1) {
                sum += needMP[value];
                continue;
            }

            auto comp = [&](const pil &a, const pil &b) { return a.second > b.second; };
            priority_queue<pil, vector<pil>, decltype(comp)> q(comp);

            q.push(make_pair(value, 0));
            vector<bool> visited(10, false);

            while(!q.empty()) {

                auto node = q.top(); q.pop();
                int index = node.first;
                ll distance = node.second;

                if (visited[index])
                    continue;

                if(index == 1) {
                    needMP[value] = distance;
                    sum += distance;
                    break;
                }

                visited[index] = true;

                for(int i = 0; i <= 9; ++i) {
                    q.push(make_pair(i, distance + mp[index][i]));

                }
                
            }

        }
    }

    cout << sum << endl;

    return 0;
}