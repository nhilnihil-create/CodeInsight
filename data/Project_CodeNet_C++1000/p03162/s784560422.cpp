#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, el;
    cin >> n;
    vector<int> happiness[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) {
            cin >> el;
            happiness[i].push_back(el);
        }

    for (int i = 1; i < n; i++)
        for (int j = 0; j < 3; j++) {
            int maxx = 0;
            for (int k = 0; k < 3; k++)
                if (k != j && happiness[i - 1][k] > maxx)
                    maxx = happiness[i - 1][k];
            happiness[i][j] += maxx;
        }
    cout << max(max(happiness[n - 1][0], happiness[n - 1][1]), happiness[n - 1][2]);

    return 0;
}