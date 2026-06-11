#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int H, W, N; cin >> H >> W >> N;
    vector<pair<int, int>> A;
    for (int i = 0; i < N; i++) {
        int X, Y; cin >> X >> Y;
        if (X >= Y) {
            A.emplace_back(X, Y);
        }
    }
    sort(A.begin(), A.end());
    int k = 0;
    for (auto p : A) {
        int x = p.first, y = p.second;
        if (x - y == k) {
            k++;
        } else if (x - y > k) {
            cout << x - 1 << endl;
            return 0;
        }
    }
    cout << H << endl;
    return 0;
}
