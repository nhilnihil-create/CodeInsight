#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

const int INF = 1001001001;
typedef long long ll;
typedef pair<int,int> pint;

int dist[101010];
int k;
int bfs(){
    deque<pint> q;
    q.push_back({1,1});
    dist[1] = 1;
    while(!q.empty()){
        pint p = q.front();
        q.pop_front();
        //現在地
        int now = p.first;
        //現在地までのコスト
        int d = p.second;
        int next = (now+1)%k;
        if(dist[next] > d+1){
            dist[next] = d+1;
            q.push_back({next,d+1});
        }
        next = (now*10) % k;
        if(dist[next] > d){
            dist[next] = d;
            q.push_back({next,d});
        }
    }
    return dist[0];

}

int main(){
    
    cin >> k;
    rep(i,k){
        dist[i] = INF;
    }
    cout<<bfs()<<endl;
    

    

}