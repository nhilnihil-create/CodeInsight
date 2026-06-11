#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <deque>
#include <queue>
using namespace std;

typedef long long ll;
vector<vector<int>> path(10005);

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a,b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    vector<int> c(N);
    ll sum = 0;
    for(int i = 0; i < N; i++){
        cin >> c[i];
        sum += c[i];
    }
    sort(c.begin(), c.end(), greater<>());
    sum -= c[0];
    queue<pair<int, int>> q;

    vector<int> ans(N+1);
    ans[1] = c[0];
    q.push(make_pair(1, -1));
    int idx = 1;

    while(!(q.empty())){
        int now = q.front().first;
        int p = q.front().second;
        for(int i = 0; i < path[now].size(); i++){
            if(path[now][i] == p) continue;
            q.push(make_pair(path[now][i], now));
            ans[path[now][i]] = c[idx];
            idx++;
        }
        q.pop();
    }
    cout << sum << endl;
    for(int i = 1; i <= N; i++)
        cout << ans[i] << endl;
}

