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
#define ll long long

using namespace std;

long long MOD = 1000000007;

void dfs(int x, int d, vector<vector<int>> &edge, vector<int> &dist){
    if(dist[x]>0){
        return;
    }
    dist[x]=d;

    for(auto &e:edge[x]){
        dfs(e, d+1, edge, dist);
    }
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
    vector<vector<int>> edge(N,vector<int>(0));
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<int> dist(N,-1);
    dfs(0, 0, edge, dist);

    //cout_vec(dist);
    int x, d;
    d=0;
    for(int i=0; i<N; i++){
        if(dist[i]>d){
            d=dist[i];
            x=i;
        }
        dist[i]=0;
    }
    //cout_vec(dist);

    dfs(x, 0, edge, dist);
    int dia=0;
    for(int i=0; i<N; i++){
        dia=max(dia,dist[i]);
    }
    //cout_vec(dist);
    if(dia%3==1){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
}