#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, X; cin >> N >> X;
    vector<int> m(N, 0);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> m[i]; sum += m[i];
    }
    sort(m.begin(), m.end());
    int cnt = N;
    X -= sum;
    while (X >= m[0]) {
        X -= m[0];
        cnt++;
    }
    printf("%d\n", cnt);
}
