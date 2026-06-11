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
#include <tuple>

using namespace std;

long long MOD = 1000000007;

void bfs(int root, vector<pair<int, int> > &vec, vector<int> &cnt, vector<vector<int> > &edges){
    deque<tuple<int, int, int> > que;
    que.push_back(make_tuple(0, 0, root));
    while((int) que.size()>0){
        int r=get<0>(que.front());
        int p=get<1>(que.front());
        int now=get<2>(que.front());
        que.pop_front();
        cnt[now]--;

        if(vec[now].first < r){
            vec[now]=make_pair(r,p);
        }
        if(cnt[now]>0)continue;

        for(int i=0; i<(int)edges[now].size(); i++){
            int next_=edges[now][i];
            que.push_back(make_tuple(r+1, now, next_));
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int> > edges(N,vector<int>(0));
    vector<pair<int, int> > vec(N,make_pair(0,-1));
    vector<int> cnt(N,0);
    for(int i=0; i<N+M-1; i++){
        int A, B;
        cin >> A >> B;
        A--;B--;
        edges[A].push_back(B);
        vec[B]=make_pair(-2,-2);
        cnt[B]++;
    }
    
    for(int i=0; i<N; i++){
        if(vec[i].second==-1){
            bfs(i, vec, cnt, edges);
            break;
        }
    }
    for(int i=0; i<N; i++){
        //cout << vec[i].first << ' ';
        cout << vec[i].second+1 << endl;
    }
}