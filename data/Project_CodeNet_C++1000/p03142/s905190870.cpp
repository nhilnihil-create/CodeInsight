#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> in_num(N, 0);
    vector<vector<int> > e(N, vector<int>());
    vector<int> ans(N, 0);
    for(int i=0; i<N-1+M; i++) {
        int s, t;
        cin >> s >> t;
        e[s-1].push_back(t-1);
        in_num[t-1]++;
    }
    
    queue<int> que;
    for(int i=0; i<N; i++) {
        if(in_num[i]) {
            ;
        } else {
            que.push(i);
        }
    }
    
    while(!que.empty()) {
        int cur=que.front();
        que.pop();
        
        for(int i=0; i<e[cur].size(); i++) {
            in_num[e[cur][i]]--;
            if(in_num[e[cur][i]]) {
                ;
            } else {
                que.push(e[cur][i]);
                ans[e[cur][i]] = cur+1;
            }
        }
    }
    
    for(int i=0; i<N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
    
}