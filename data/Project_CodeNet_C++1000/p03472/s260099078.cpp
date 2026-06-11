#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, H;
    cin >> N >> H;
    priority_queue<pair<int, int> > katanas;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        katanas.push(make_pair(b, 1)); // throw;
        katanas.push(make_pair(a, 0)); // hit
    }

    int ans = 0;
    while (H > 0) {
        auto e = katanas.top();
        katanas.pop();
        if (e.second == 1) { // throw
            H -= e.first;
            ++ans;
        }
        else { // hit
            ans += H / e.first;
            if (H % e.first != 0) {
                ++ans;
            }
            break;
        }
    }

    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
