#include <bits/stdc++.h>
using namespace std;

int maxHappiness(vector<vector<int>>& tasks, int row, int col, vector<vector<int>>& mem){
    if(row >= tasks.size()) return 0;

    if(mem[row][col] != -1) return mem[row][col];

    int ans = INT_MIN;
    for(int i = 0; i < 3; i++){
        if(i == col) continue;

        ans = max(ans, tasks[row][col]+maxHappiness(tasks, row+1, i, mem));
    } 

    mem[row][col] = ans;
    return ans;
}

int main(){
    int N;
    cin >> N;

    vector<vector<int>> tasks(N, vector<int>(3));
    vector<vector<int>> mem(N, vector<int>(3, -1));
    for(int i = 0; i < N; i++){
        cin >> tasks[i][0] >> tasks[i][1] >> tasks[i][2];
    }

    int ans = INT_MIN;
    for(int i = 0; i < 3; i++){
        ans = max(ans, maxHappiness(tasks, 0, i, mem));
    }
    cout << ans << endl;
}