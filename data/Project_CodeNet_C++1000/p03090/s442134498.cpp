#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> edges;
    for(int i=1; i<=N; i++){
        int ng;
        if(N%2){
            ng = N-i;
        }else{
            ng = N+1-i;
        }
        for(int j=1; j<i; j++) if(j != ng) edges.emplace_back(i, j);
    }
    cout << edges.size() << endl;
    for(auto& p : edges) cout << p.first << " " << p.second << endl;
}
