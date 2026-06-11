#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int NMax = 200005;
int N;
queue <int> Q;
vector <int> G[NMax];
int Dist[NMax];
void Read(){
    cin >> N;
    for(int i = 1; i < N; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

void BFS(int start){
    for(int i = 1; i <= N; i++)
        Dist[i] = -1;
    Dist[start] = 0;
    Q.push(start);
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        for(int i = 0; i < G[node].size(); i++){
            int neighb = G[node][i];
            if(Dist[neighb] != -1)
                continue;
            Dist[neighb] = Dist[node] + 1;
            Q.push(neighb);
        }
    }
}

int findMaxDistanceNode(){
    int ans = 1, Max = Dist[1];
    for(int i = 2; i <= N; i++){
        if(Dist[i] > Max){
            Max = Dist[i];
            ans = i;
        }
    }
    return ans;
}

int findDiameter(){
    BFS(1);
    int newStart = findMaxDistanceNode();
    BFS(newStart);
    return Dist[findMaxDistanceNode()];
}

void Solve(){
    int diameter = findDiameter();
    if(diameter % 3 == 1)
        cout << "Second\n";
    else
        cout << "First\n";
}
int main()
{
    Read();
    Solve();
    return 0;
}
