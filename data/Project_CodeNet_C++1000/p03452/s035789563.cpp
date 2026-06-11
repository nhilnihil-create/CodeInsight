#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const int INF=(int)-2e9;

vector<pair<int,int>> to[100005];

int main() {
    int N,M;
    cin>>N>>M;

    int L,R,D;
    for (int i = 0; i < M; ++i) {
        cin>>L>>R>>D; L--; R--;
        to[L].push_back(make_pair(R,D));
        to[R].push_back(make_pair(L,-D));
    }

    vector<int> dist(N,INF);
    for (int i = 0; i < N; ++i) {
        if(dist[i]>INF) continue;
        queue<int> q;
        dist[i]=0;
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto tsugi:to[node]){
                if(dist[tsugi.first]==INF){
                    dist[tsugi.first]=dist[node]+tsugi.second;
                    q.push(tsugi.first);
                }else{
                    if(dist[tsugi.first]!=dist[node]+tsugi.second){
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}