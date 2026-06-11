// :)
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
// typedef priority_queue<int, vector<int>, greater<int>> min_pq;

std::random_device rd_device;
std::mt19937 rng(rd_device());

template<typename T>
void printVec(vector<T> &vec) {
    for (auto &v : vec) cout<<v<<" ";
    cout<<endl;
}

void sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int main() {
    std::srand(std::time(0));
    ios::sync_with_stdio(false);
//    cin.exceptions(ios_base::failbit);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    cout<<fixed;
    
    int n;
    cin>>n;
    vector<vector<int>> graph(n);
    for (int i=0;i<n-1;i++) {
        int u, v;
        cin>>u>>v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    vector<int> used(n);
    q.push(0);
    used[0] = 1;
    int last = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto next : graph[curr]) {
            if (used[next]) continue;
            q.push(next);
            used[next] = 1;
        }
        if (q.empty()) last = curr;
    }
    queue<vector<int>> qq;
    used = vector<int>(n);
    int u = last;
    used[u] = 1;
    qq.push({u, 0});
    int m = 0;
    int l = -1;
    while (!qq.empty()) {
        vector<int> curr = qq.front();
        qq.pop();
        for (auto next : graph[curr[0]]) {
            if (used[next]) continue;
            qq.push({next, curr[1]+1});
            if (curr[1]+1 > m) {
                m = curr[1]+1;
                l = next;
            }
            used[next] = 1;
        }
    }
    m++;
    if (m%3 == 2) cout<<"Second"<<endl;
    else cout<<"First"<<endl;

    return 0;
}
