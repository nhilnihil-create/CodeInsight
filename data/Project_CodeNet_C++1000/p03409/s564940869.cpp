#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<pair<int, int>> red(N), blue(N);
    for (int i = 0; i < N; i++) {
        cin >> red[i].first >> red[i].second;
    }
    for (int i = 0; i < N; i++) {
        cin >> blue[i].first >> blue[i].second;
    }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    int count = 0;
    vector<int> memo(N, -1);
    for (int i = 0; i < N; i++) { //blue[i]
        int it = -1; int val = -1;
        for (int j = 0; j < N; j++) { //red[i]
            if (memo[j] != -1) continue;
            if (blue[i].first > red[j].first) {
                if (blue[i].second > red[j].second) {
                    if (red[j].second > val) {
                        val = red[j].second;
                        it = j;
                    }
                }
            }
        }
        if (it != -1) {
            memo[it] ++;
            count ++;
        }
    }
    cout << count << endl;
}