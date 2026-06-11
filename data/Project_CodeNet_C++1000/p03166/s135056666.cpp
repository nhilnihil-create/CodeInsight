#include <iostream>
#include <vector>
using namespace std;

int maxPath(vector<vector<int> >& graph, vector<int>& memo, int vertex) {
    if(memo[vertex] != -1) return memo[vertex];

    if(graph[vertex].empty()) {
        memo[vertex] = 0;
    } else {
        for(int prev : graph[vertex]) {
            memo[vertex] = max(memo[vertex], 1 + maxPath(graph, memo, prev));
        }
    }
    
    return memo[vertex];
}

int main() {
    int numVertices;
    cin >> numVertices;
    int numEdges;
    cin >> numEdges;

    vector<vector<int> > graph(numVertices, vector<int>());
    int from, to;
    for(int i = 0; i < numEdges; i++) {
        cin >> from;
        cin >> to;
        graph[to-1].push_back(from-1);
    }

    //stores max path if ending at that vertex
    vector<int> memo(numVertices, -1);
    int result = 0;
    for(int vertex = 0; vertex < numVertices; vertex++) {
        result = max(result, maxPath(graph, memo, vertex));
    }
    cout << result;
    return 0;
}