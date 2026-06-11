#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int, long long int> x, pair<int, long long int> y) {
    if(x.second!=y.second) {
        return x.second > y.second;
    } else {
        return x.second < y.second;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, long long int> > TD(N);
    for(int n=0; n<N; n++) {
        cin >> TD[n].first >> TD[n].second;
    }
    
    sort(TD.begin(), TD.end(), cmp);
    // cout << TD[0].second << endl;
    
    vector<long long int> ans(N+1, 0);
    long long int tmp_ans=0;
    auto c = [](pair<int, long long int> x, pair<int, long long int> y) {
        if(x.second!=y.second) {
            return x.second > y.second;
        } else {
            return x.first < y.first;
        }
    };
    priority_queue<pair<int, long long int>, vector<pair<int, long long int> >, decltype(c)> que(c);
    vector<int> group_counter(N+1, 0);
    int V=0;
    for(int k=0; k<K; k++) {
        if(group_counter[TD[k].first]==0) V++;
        group_counter[TD[k].first]++;
        que.push(TD[k]);
        tmp_ans += TD[k].second;
    }
    ans[V] = tmp_ans;
    // cout << que.top().second << endl;
    // cout << group_counter[1] << endl;
    
    int cur_k=K;
    int v=V;
    while(!que.empty() && cur_k<N) {
        tmp_ans = ans[v];
    
        while(!que.empty() && group_counter[que.top().first]==1) {
            que.pop();
        }
        
        if(que.empty()) break;
        
        tmp_ans -= que.top().second;
        group_counter[que.top().first]--;
        que.pop();

        while(cur_k<N && group_counter[TD[cur_k].first]>0) {
            cur_k++;
        }
        if(cur_k<N) {
            group_counter[TD[cur_k].first]++;
            tmp_ans += TD[cur_k].second;
            v++;
            ans[v] = tmp_ans;
        }
        
        
        cur_k++;
    }

    long long int max_ans=0;
    for(int vi=V; vi<=v; vi++) {
        max_ans = max(max_ans, ans[vi]+(long long int)vi*vi);
    }
    
    cout << max_ans << endl;

    return 0;
    
}