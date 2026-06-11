#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

vector<int> bfs(vector<bool> &used, priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que, vector<vector<int> > &neigh, vector<int> &n_neigh, priority_queue<int, vector<int>, greater<int> > cvec){
    vector<int> ans((int) cvec.size(), 0);
    while((int) que.size() > 0){
        int vertex=que.top().second;
        que.pop();
        if(used[vertex]==true){
            continue;
        }

        used[vertex]=true;
        ans[vertex]=cvec.top();
        cvec.pop();
        
        for(int i=0; i<(int) neigh[vertex].size(); i++){
            int next = neigh[vertex][i];
            n_neigh[next]--;
            que.push(make_pair(n_neigh[next], next));
        }
    }
    return ans;
}

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int> > neigh(N, vector<int>(0));
    vector<int> n_neigh(N,0);
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        neigh[a].push_back(b);
        neigh[b].push_back(a);
        n_neigh[a]++;
        n_neigh[b]++;
    }

    priority_queue<int, vector<int>, greater<int> > cvec;
    int sum_=0;
    int max_=0;
    for(int i=0; i<N; i++){
        int c;
        cin >> c;
        cvec.push(c);
        sum_+=c;
        max_=max(max_,c);
    }
    sum_-=max_;

    vector<bool> used(N,false);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    for(int i=0; i<N; i++){
        if(n_neigh[i]==1){
            que.push(make_pair(1, i));
        }
    }

    vector<int> ans = bfs(used, que, neigh, n_neigh, cvec);
    cout << sum_ << endl;
    cout_vec(ans);

}