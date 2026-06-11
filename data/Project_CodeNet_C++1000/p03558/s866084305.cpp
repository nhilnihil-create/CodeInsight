#include <bits/stdc++.h>
using namespace std;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}


const int INF = 1 << 29;
vector<pii> G[100010];
int d[100010];

int main(){
    int K;
    cin >> K;
    for(int i = 0; i < K; i++){
        G[i].push_back(make_pair((i+1)%K,  1));
        G[i].push_back(make_pair((i*10)%K, 0));
    }

    for(int i = 0; i < K; i++) d[i] = INF;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[1] = 1;
    pq.push(pii(1, 1));
    while(pq.size()) {
        pii p = pq.top(); pq.pop();
        if(d[p.second] < p.first) continue;
        for(pii e : G[p.second]){
            int to = e.first;
            int e_cost = e.second;
            int ncost  = e_cost + p.first;
            if(d[to] > ncost){
                d[to] = ncost;
                pq.push(pii(d[to], to));
            }
        }
    }
    cout << d[0] << endl;

    return 0;
}
