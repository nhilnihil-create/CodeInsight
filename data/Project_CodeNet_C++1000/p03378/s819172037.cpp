#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, M, X;
    cin >> N >> M >> X;

    map<int, int> cost;
    for (int i=0; i<M; i++){
        int temp;
        cin >> temp;
        cost[temp]++; 
    }

    int cost_r = 0,cost_l = 0;
    for (int i=X; i<N+1; i++){
        if (cost.count(i)) cost_r++;
    }
    for (int i=X; i>=0; i--){
        if (cost.count(i)) cost_l++;
    }

    cout << min(cost_l, cost_r) << endl;
    return 0;
}