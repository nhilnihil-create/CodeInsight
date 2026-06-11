//
//  main.cpp
//
 
#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
 
struct Edge {
    int from;
    int to;
};
 
vector<vector<Edge>> graph;
vector<int> top_ordered;
vector<bool> visited;
 
void dfs(int now) {
    for (Edge e : graph[now]) {
        if (e.from == now && !visited[e.to]) {
            dfs(e.to);
        }
    }
    visited[now] = true;
    top_ordered.push_back(now);
}
 
int main() {
    int N, M;
    cin >> N >> M;
    graph.resize(N);
    for (int i = 0; i < N-1+M; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        graph[A].push_back(Edge{A, B});
        graph[B].push_back(Edge{A, B});
    }
    int root = 0;
    while (true) {
        int bak_root = root;
        for (Edge e : graph[root]) {
            if (e.to == root) {
                root = e.from;
                break;
            }
        }
        if (bak_root == root) {
            break;
        }
    }
    visited.resize(N, false);
    dfs(root);
    reverse(top_ordered.begin(), top_ordered.end());
    vector<int> top_order(N);
    for (int i = 0; i < N; i++) {
        top_order[top_ordered[i]] = i;
    }
    for (int i = 0; i < N; i++) {
    	if (i == root) {
    		cout << 0 << endl;
    	} else {
    		int max = numeric_limits<int>::min();
    		int par_idx = -1;
    		for (Edge e : graph[i]) {
    			if (e.to == i && top_order[e.from] > max) {
    				par_idx = e.from;
    				max = top_order[e.from];
    			}
    		}
    		cout << par_idx + 1 << endl;
    	}
    }
}
 