#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> edge;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(n&1) {
                if(i+j != n) edge.push_back({i, j});
            }
            else {
                if(i+j != n+1) {
                    edge.push_back({i, j});
                }
            }
        }
    }
    cout << edge.size() << endl;
    for(auto t : edge) {
        cout << t.first << " " << t.second << endl;
    }
    return 0;
}

