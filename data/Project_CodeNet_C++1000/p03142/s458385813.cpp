#include <iostream>
#include<iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <list>
#include <string>
#include <numeric>
#include <utility>
using namespace std;

//long long A[100000];
//int stand_bit_num[40];

//int t[1000000];
//long long d[100000];

vector <int> edges[100000];
vector <int> reverse_edges[100000];
int parent[100000];
int used_reverse_edge_count[100000];

int main(){
    int N;
    int M;
    
    cin >> N >> M;

    for(int i = 0; i <N + M - 1; i++){
        int a;
        int b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        reverse_edges[b-1].push_back(a-1);
    }

    int source;
    for(int i = 0; i <N; i++){
        if(reverse_edges[i].size() == 0){
            source = i;
            break;
        }
    }
    for(int i = 0; i < N; i++){
        used_reverse_edge_count[i] = 0;
    }

    queue <pair <int, int> > q;
    q.push(make_pair(-1, source));

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int prev = p.first;
        int cur = p.second;
        if(used_reverse_edge_count[cur] < (int)reverse_edges[cur].size() - 1){
            used_reverse_edge_count[cur] ++;
            continue;
        }
        parent[cur] = prev;

        for(int i = 0; i < edges[cur].size(); i++){
            q.push(make_pair(cur, edges[cur][i]));
        }
    }

    for(int i = 0; i < N; i++){
        cout << parent[i] + 1 << endl;
    }

    return 0;
}