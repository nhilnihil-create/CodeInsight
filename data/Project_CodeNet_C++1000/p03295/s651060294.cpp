#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> AB(M);
    for (int i = 0; i < M; i++){
        cin >> AB.at(i).first >> AB.at(i).second;
    }
    sort(AB.begin(), AB.end());

    int ans = 1;
    int MAX = 1e9;
    for (int i = 0; i < M; i++) {
        if (AB.at(i).first < MAX) {
            MAX = min(MAX, AB.at(i).second);
        }
        else {
            ans++;
            MAX = AB.at(i).second;
        }
    }

    cout << ans << endl;

    return 0;
}
