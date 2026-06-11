#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, i, cost, cost_sum = 0, max_cost = 0;
    cin >> N;
    
    for (i=0; i < N; i++) {
        cin >> cost;
        cost_sum += cost;
        if (max_cost < cost) {
            max_cost = cost;
        }
        // cout << endl << cost_sum << endl;
    }
    max_cost = max_cost / 2;
    cost_sum -= max_cost;

    cout << cost_sum << endl;
    return 0;
}
