#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, L; cin >> N;
    if (N % 2 == 0){
        M = N / 2;
        L = (N + 1);
    } else {
        M = (N + 1) / 2;
        L = N;
    }

    vector<vector<int> > group(M, {0});
    for (int i = N; 1 <= i; i--) {
        int j = 0;
        while (true) {
            if (group[j][0] + i > L) {
                j++;
            } else {
                break;
            }
        }
        group[j].push_back(i);
        group[j][0] += i;
    }
    vector<pair<int ,int> > ans;

    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = 1; k < group[i].size(); k++){
                for (int l = 1; l < group[j].size(); l++) {
                    ans.push_back({group[i][k], group[j][l]});
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
}