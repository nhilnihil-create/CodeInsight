#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int K;
vector<pair<int,int> > G[100000];
int d[100000];

void bfs(int v){
    fill(d,d+K,-1);
    deque<pair<int,int> > deq;
    deq.push_back(make_pair(v,0));
    pair<int,int> pa;
    int from,to,cost,zeroone;
    int i;
    while(!deq.empty()){
        pa= deq.front();
        deq.pop_front();
        from=pa.first;
        cost=pa.second;
        if(d[from]>=0) continue;
        d[from]=cost;
        for(i=0; i<G[from].size(); i++){
            pa=G[from][i];
            to=pa.first;
            zeroone=pa.second;
            if(d[to]<0){
                if(zeroone==0){
                    deq.push_front(make_pair(to,cost));
                }else{
                    deq.push_back(make_pair(to,cost+1));
                }
            }
        }
    }

}

int main(){
    cin >> K;
    int i;
    for(i=0; i<K-1; i++){
        G[i].push_back(make_pair((10*i)%K,0));
        G[i].push_back(make_pair(i+1,1));
    }
    G[K-1].push_back(make_pair((10*(K-1))%K,0));
    G[K-1].push_back(make_pair(0,1));
    bfs(1);
    cout << d[0]+1 << endl;
    system("pause");
    return 0;
}