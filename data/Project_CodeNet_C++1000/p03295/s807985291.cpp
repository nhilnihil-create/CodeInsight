#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main(){

    int N, M;
    vector<pair<int, int>> combat;
    cin >> N >> M;
    combat.resize(M);
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        combat[i] = make_pair(a - 1, b - 1);
    }

    sort(combat.begin(), combat.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; });

    int ans = 1;
    int end = combat[0].second;
    for (int i = 1; i < M; i++){
        if(combat[i].first >= end){
            ans++;
            end = combat[i].second;
        }
    }
        cout << ans << endl;
}