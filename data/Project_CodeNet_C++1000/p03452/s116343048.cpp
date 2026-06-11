#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<deque>

using namespace std;

#define INF 1 << 29
#define LL long long int

struct Edge{
    int a;
    int b;
    Edge(int i,int j):a(i),b(j){

    }
};

deque<int> deq;
vector<vector<Edge>> edge(100001);
vector<int> node(100001,0);
vector<int> cost(100001,-1);
int n,m;

bool visit(int j){
    //cout << j << " ";
    if(node[j] == 1){
        return false;
    }else if(node[j] == 0){
        node[j] = 1;
        for(int i = 0; i < edge[j].size(); i++){
            //cout << edge[j][i].a << endl;
            bool check = visit(edge[j][i].a);
            if(!check){
                return false;
            }
        }
        node[j] = 2;
        deq.push_front(j);
        return true;
    }
    return true;
}

bool dfs(int j){
    for(int i = 0; i < edge[j].size(); i++){
        if(cost[edge[j][i].a] < 0){
            cost[edge[j][i].a] = cost[j] + edge[j][i].b;
            bool check = dfs(edge[j][i].a);
            if(!check) return false;
        }else{
            if(cost[edge[j][i].a] == cost[j] + edge[j][i].b){
            }else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back(Edge(b,c));
    }

    bool circle = true;;

    for(int i = 0; i < n && circle; i++){
        if(node[i+1] == 0){
            circle = visit(i+1);
        }
    }

    if(!circle){
        cout << "No" << endl;
        return 0;
    }

    bool result = true;

    for(int i = 0; i < n && result; i++){
        int t = deq[i];
        if(cost[t] == -1){
            cost[t] = 0;
            result = dfs(t);
        }
    }

    if(result){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}