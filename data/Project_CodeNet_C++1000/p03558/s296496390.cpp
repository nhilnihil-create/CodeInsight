#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <deque>
using namespace std;

vector<int> graph;
vector<bool> visited;

deque<long long> d;


int main(){
    int k;
    cin >> k;

    for(int i = 0; i < k; i++){
        graph.push_back(1 << 30);
        visited.push_back(false);
    }

    graph[1] = 0;
    d.push_back(1);
    //cerr << "int" << endl;
    //cerr << "init" << endl;
    while(!d.empty()){
        long long i = d.front();
        //cerr << i << endl;
        d.pop_front();
        if(visited[i%k]){
            continue;
        }
        visited[i%k] = true;

        graph[(i+1)%k] = min(graph[(i+1)%k], graph[i%k]+1);
        d.push_back((i+1)%k);
        
        graph[(i*10)%k] = min(graph[(i*10)%k], graph[i%k]);
        d.push_front((i*10)%k);
    }
    cout << graph[0]+1 << endl;

    return 0;
}

