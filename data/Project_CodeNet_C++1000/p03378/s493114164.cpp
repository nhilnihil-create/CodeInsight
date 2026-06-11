#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n, m, x;
    cin >> n >> m >> x;
    vector<size_t> cost(n + 1, 0);
    for (size_t i = 0; i < m; ++i) {
        size_t a;
        cin >> a;
        cost[a] = 1;
    }
    vector<size_t> cumsum(n + 1, 0);
    for (size_t i = 1; i < n + 1; ++i) {
        cumsum[i] = cost[i] + cumsum[i - 1];
    }
    cout << min(cumsum[n] - cumsum[x], cumsum[x]) << endl;
    return EXIT_SUCCESS;
}