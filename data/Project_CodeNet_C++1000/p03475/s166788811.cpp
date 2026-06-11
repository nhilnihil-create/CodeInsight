#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n - 1), start(n - 1), width(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> cost[i] >> start[i] >> width[i];
    }
    for (int i = 0; i < n; ++i) {
        int time = 0;
        for (int j = i; j < n - 1; ++j) {
            if (time <= start[j]) {
                time = start[j] + cost[j];
            } else {
                int t = (time - start[j]) / width[j];
                if ((time - start[j]) % width[j] != 0) ++t;
                time = start[j] + width[j] * t;
                time += cost[j];
            }
        }
        cout << time << endl;
    }
}
