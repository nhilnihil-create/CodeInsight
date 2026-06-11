#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int> > path;
vector<int> seen;
void dfs(int from) {
    if(seen[from] == false) {
        seen[from] = true;
        for(int i = 0; i < path[from].size(); i++) {
            dfs(path[from][i]);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;


    //vector<vector<int> > path(N, vector<int>());
    path.assign(N, vector<int>());

    for(int i = 0; i < M ; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;y--;
        path[x].push_back(y);
        path[y].push_back(x);
    }

    seen.assign(N, false);
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(seen[i] == false) {
            dfs(i);
            cnt++;

        }
    }

    cout << cnt << endl;



}
